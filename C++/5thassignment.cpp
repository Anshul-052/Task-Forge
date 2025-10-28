#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool validateInfix(const string &expr) {
    stack<char> stack;
    bool lastWasOperator = true; 
    bool lastWasOperand = false;

    for (int i = 0; i < (int)expr.size(); i++) {
        char token = expr[i];

        if (token == ' ') continue;

        if (token == '(') {
            stack.push(token);
            lastWasOperator = true;
            lastWasOperand = false;
        }
        else if (token == ')') {
            if (stack.empty()) return false;  
            stack.pop();
            lastWasOperand = true;
            lastWasOperator = false;
        }
        else if (isOperator(token)) {
            if (lastWasOperator) return false; 
            lastWasOperator = true;
            lastWasOperand = false;
        }
        else if (isdigit(token)) {
           
            while (i < (int)expr.size() && (isdigit(expr[i]) || expr[i] == '.')) i++;
            i--;
            lastWasOperand = true;
            lastWasOperator = false;
        }
        else {
            return false; 
        }
    }
    if (!stack.empty()) return false; 
    if (!lastWasOperand) return false; 
    return true;
}


vector<string> infixToPostfix(const string &expr) {
    stack<char> stack;       
    vector<string> list;    
    string tokens;           

    for (int i = 0; i < (int)expr.size(); i++) {
        char token = expr[i];

        if (token == ' ') continue;

        if (isdigit(token)) {
            tokens = "";
            while (i < (int)expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                tokens += expr[i++];
            }
            i--;
            list.push_back(tokens);
        }
        else if (token == '(') {
            stack.push(token);
        }
        else if (token == ')') {
            while (!stack.empty() && stack.top() != '(') {
                list.push_back(string(1, stack.top()));
                stack.pop();
            }
            stack.pop(); 
        }
        else if (isOperator(token)) {
            while (!stack.empty() && precedence(stack.top()) >= precedence(token)) {
                list.push_back(string(1, stack.top()));
                stack.pop();
            }
            stack.push(token);
        }
    }

    
    while (!stack.empty()) {
        list.push_back(string(1, stack.top()));
        stack.pop();
    }

    return list;
}

double evaluatePostfix(const vector<string> &list) {
    stack<double> stack;

    for (int i = 0; i < (int)list.size(); i++) {
        string token = list[i];

        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            stack.push(stod(token));
        }
        else if (isOperator(token[0])) {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();

            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
                case '^': stack.push(pow(a, b)); break;
            }
        }
    }
    return stack.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    if (!validateInfix(infix)) {
        cout << "Invalid expression!" << endl;
        return 0;
    }

    vector<string> postfixList = infixToPostfix(infix);

    cout << "Postfix expression: ";
    for (string token : postfixList) {
        cout << token << " ";
    }
    cout << endl;

    double result = evaluatePostfix(postfixList);
    cout << "Result: " << result << endl;

    return 0;
}