# Final attempt: fill NaNs with column mean before regression, then continue.
import pandas as pd, numpy as np, textwrap
from pathlib import Path
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt, networkx as nx
from caas_jupyter_tools import display_dataframe_to_user

out_dir = Path("/mnt/data/sem_outputs")
efa_loadings = pd.read_csv(out_dir/"efa_loadings.csv", index_col=0)
latent_df = pd.read_csv(out_dir/"latent_scores.csv")
numeric = pd.read_csv(out_dir/"cleaned_preview.csv")

# Recreate top_inds and construct_labels
efa_loadings.index = efa_loadings.index.astype(str)
factors = list(efa_loadings.columns)
top_inds = {}
for f in efa_loadings.columns:
    ser = efa_loadings[f].abs().sort_values(ascending=False)
    top = ser[ser >= 0.35].index.tolist()
    if len(top) == 0:
        top = ser.head(3).index.tolist()
    top_inds[f] = top[:6]

def make_label(var_list):
    parts = []
    for v in var_list[:3]:
        w = str(v).replace("_"," ").split()
        parts.append(w[0][:8])
    return "_".join(parts)

construct_labels = {f: make_label(top_inds[f]) for f in efa_loadings.columns}

# Reliability DF (recompute quickly)
def cronbach_alpha(df):
    k = df.shape[1]
    if k <= 1:
        return np.nan
    item_vars = df.var(axis=0, ddof=1)
    total_var = df.sum(axis=1).var(ddof=1)
    if total_var == 0:
        return np.nan
    alpha = (k / (k-1)) * (1 - item_vars.sum() / total_var)
    return alpha

reliability_rows = []
for f in efa_loadings.columns:
    cname = construct_labels[f]
    indicators = [v for v in top_inds[f] if v in numeric.columns]
    if len(indicators) == 0:
        reliability_rows.append({"Construct": cname, "n_indicators": 0, "Cronbach_alpha": np.nan, "Composite_Reliability": np.nan, "AVE": np.nan})
        continue
    data_ind = numeric[indicators]
    alpha = cronbach_alpha(data_ind)
    std_loads = efa_loadings.loc[indicators, f].astype(float)
    lam = np.nan_to_num(std_loads.values)
    num = lam.sum()**2
    denom = num + ((1 - lam**2).sum())
    cr = num/denom if denom!=0 else np.nan
    ave = (lam**2).sum()/len(lam) if len(lam)>0 else np.nan
    reliability_rows.append({"Construct": cname, "n_indicators": len(indicators), "Cronbach_alpha": round(float(alpha) if not np.isnan(alpha) else np.nan,3), "Composite_Reliability": round(float(cr) if not np.isnan(cr) else np.nan,3), "AVE": round(float(ave) if not np.isnan(ave) else np.nan,3)})

reliability_df = pd.DataFrame(reliability_rows)
reliability_df.to_csv(out_dir/"reliability_metrics.csv", index=False)

# Prepare latent_df columns to match efa factors (in case of mismatch)
latent_df.columns = efa_loadings.columns[:latent_df.shape[1]].tolist()
# Standardize and fill NaNs
std_latent = (latent_df - latent_df.mean())/latent_df.std(ddof=0)
std_latent = std_latent.fillna(std_latent.mean()).fillna(0)

factors_std = list(std_latent.columns)
endogenous = factors_std[-1]
exogenous = factors_std[:-1]

X = std_latent[exogenous].values
y = std_latent[endogenous].values
lr = LinearRegression().fit(X,y)
coefs = pd.Series(lr.coef_, index=exogenous)
r2 = lr.score(X,y)

# Bootstrap (500 for speed)
import numpy as np
n_boot = 500
rng = np.random.RandomState(123)
boot_coefs = np.zeros((n_boot, len(exogenous)))
for i in range(n_boot):
    idx = rng.randint(0, std_latent.shape[0], std_latent.shape[0])
    Xb = std_latent.iloc[idx][exogenous].values
    yb = std_latent.iloc[idx][endogenous].values
    try:
        lr_b = LinearRegression().fit(Xb, yb)
        boot_coefs[i,:] = lr_b.coef_
    except Exception:
        boot_coefs[i,:] = np.nan

coef_df = pd.DataFrame({
    "exogenous": exogenous,
    "coef": coefs.values,
    "boot_se": boot_coefs.std(axis=0, ddof=1),
    "boot_mean": boot_coefs.mean(axis=0),
    "ci_lower": np.percentile(boot_coefs, 2.5, axis=0),
    "ci_upper": np.percentile(boot_coefs, 97.5, axis=0)
})
pvals = []
for j in range(len(exogenous)):
    obs = coefs.values[j]
    boots = boot_coefs[:,j]
    p = np.mean(np.abs(boots) >= abs(obs))
    pvals.append(p)
coef_df["p_value"] = pvals
coef_df["sig"] = coef_df["p_value"].apply(lambda p: "***" if p<0.001 else "**" if p<0.01 else "*" if p<0.05 else "")
coef_df.to_csv(out_dir/"path_coefficients_bootstrap.csv", index=False)

# Path diagram
plt.figure(figsize=(10,6))
G = nx.DiGraph()
factor_to_construct = {f: construct_labels[f] for f in efa_loadings.columns}
for ex in exogenous:
    G.add_node(factor_to_construct[ex])
G.add_node(factor_to_construct[endogenous])
for ex in exogenous:
    G.add_edge(factor_to_construct[ex], factor_to_construct[endogenous], weight=float(coefs.loc[ex]))

pos = {}
left_x = 0.08
right_x = 0.85
y_space = np.linspace(0.9, 0.1, len(exogenous))
for i, ex in enumerate(exogenous):
    pos[factor_to_construct[ex]] = (left_x, y_space[i])
pos[factor_to_construct[endogenous]] = (right_x, 0.5)

nx.draw_networkx_nodes(G, pos, node_size=3000, node_color="white", edgecolors="black")
nx.draw_networkx_labels(G, pos, font_size=9)
nx.draw_networkx_edges(G, pos, arrowstyle='->', arrowsize=18, width=2)
edge_labels = {}
for u,v,d in G.edges(data=True):
    ex_key = None
    for k,vv in factor_to_construct.items():
        if vv == u:
            ex_key = k; break
    sig = coef_df.loc[coef_df["exogenous"]==ex_key, "sig"].values[0]
    edge_labels[(u,v)] = f"{d['weight']:.3f}{sig}"
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=9)
plt.title(f"PLS-SEM Path Diagram (std. coefficients) — Endog: {factor_to_construct[endogenous]}\nR² = {r2:.3f}    (n={numeric.shape[0]})")
plt.axis('off')
diagram_path = out_dir/"path_diagram_publication.png"
plt.savefig(diagram_path, dpi=300, bbox_inches="tight")
plt.close()

# Display outputs for user
display_dataframe_to_user("Constructs (top indicators per factor)", pd.DataFrame([{"Factor": f, "Construct_label": construct_labels[f], "Top_indicators": ", ".join(top_inds[f])} for f in efa_loadings.columns]))
display_dataframe_to_user("Reliability & Validity metrics (Cronbach alpha, CR, AVE)", reliability_df)
display_dataframe_to_user("PLS-SEM path coefficients (standardized) with bootstrap CI & p-values", coef_df)

print("Saved files:")
for p in [out_dir/"efa_loadings.csv", out_dir/"efa_communalities.csv", out_dir/"latent_scores.csv", out_dir/"reliability_metrics.csv", out_dir/"path_coefficients_bootstrap.csv", diagram_path]:
    print("-", p)

print("\nDone.")
