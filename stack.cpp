#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool BalancedParenthesis(string s) {
    stack<char> st;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                return false;
            }
            char ch = st.top();
            st.pop();
            if (s[i] == ']' && ch != '[' || s[i] == '}' && ch != '{' || s[i] == ')' && ch != '(') {
                return false;
            }
        }
    }
    return st.empty();
}

string infixToPostfix(string s) {
    stack<char> st;
    string res = "";

    for (int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9' ||
            s[i] >='a' && s[i] <= 'z'||
            s[i] >= 'A' && s[i] <= 'Z'){
                res += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

int evaluatePostfix(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else {
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.pop();

            int result = 0;
            switch (s[i]) {
                case '*':
                 result = top2 * top1; 
                 break;
                case '/':
                 result = top2 / top1; 
                 break;
                case '+': 
                result = top2 + top1; 
                break;
                case '-': 
                result = top2 - top1; 
                break;
            }
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    int choice;
    while (choice == 4); {
        cout << "\nMenu:\n";
        cout << "1. Evaluate Postfix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Check Balanced Parentheses\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1: {
                string postfix;
                cout << "Enter the postfix expression to evaluate: ";
                cin >> postfix;
                cout << "Result: " << evaluatePostfix(postfix) << endl;
                break;
            }

            case 2: {
                string infix;
                cout << "Enter the infix expression to convert: ";
                cin >> infix;
                cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
                break;
            }

            case 3: {
                string expr;
                cout << "Enter the string with parentheses: ";
                cin >> expr;
                if (BalancedParenthesis(expr)) {
                    cout << "The string has balanced parentheses." << endl;
                } else {
                    cout << "The string does not have balanced parentheses." << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } 

    return 0;
}