```cpp
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

// BFS: finds shortest path
vector<char> bfs(map<char, vector<char>> &graph, char start, char goal) {
    queue<vector<char>> q;
    set<char> visited;
    
    q.push({start});
    
    while (!q.empty()) {
        vector<char> path = q.front();
        q.pop();
        
        char node = path.back();
        if (node == goal) return path;
        
        if (!visited.count(node)) {
            visited.insert(node);
            for (char neighbor : graph[node]) {
                vector<char> new_path = path;
                new_path.push_back(neighbor);
                q.push(new_path);
            }
        }
    }
    return {};
}

// DFS: finds any path (not guaranteed shortest)
bool dfsHelper(map<char, vector<char>> &graph, char node, char goal,
               set<char> &visited, vector<char> &path) {
    path.push_back(node);
    if (node == goal) return true;
    
    visited.insert(node);
    for (char neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            if (dfsHelper(graph, neighbor, goal, visited, path)) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

vector<char> dfs(map<char, vector<char>> &graph, char start, char goal) {
    set<char> visited;
    vector<char> path;
    dfsHelper(graph, start, goal, visited, path);
    return path;
}

int main() {
    // Define city map
    map<char, vector<char>> city_map = {
        {'A', {'B','D'}},
        {'B', {'A','C','D'}},
        {'C', {'B','E','F'}},
        {'D', {'A','B','E'}},
        {'E', {'C','D'}},
        {'F', {'C'}}
    };
    
    char start = 'A';  // Home
    char goal = 'F';   // Hospital
    
    vector<char> path_bfs = bfs(city_map, start, goal);
    vector<char> path_dfs = dfs(city_map, start, goal);
    
    cout << "BFS (shortest) path: ";
    for (char c : path_bfs) cout << c << " ";
    cout << endl;
    
    cout << "DFS (a) path: ";
    for (char c : path_dfs) cout << c << " ";
    cout << endl;
    
    return 0;
}
```
