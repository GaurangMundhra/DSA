#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^'; // ^ is right-associative
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c);
}

void infix_to_postfix() {
    string s;
    cout << "Enter infix equation: ";
    getline(cin >> ws, s); // Read entire line including spaces

    stack<char> st;
    string ans = "";

    for (char c : s) {
        if (isOperand(c)) {
            ans += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop(); // Pop the '('
            else {
                cout << "Error: Mismatched parentheses.\n";
                return;
            }
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(c) < precedence(st.top()) ||
                   (precedence(c) == precedence(st.top()) && !isRightAssociative(c)))) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        if (st.top() == '(') {
            cout << "Error: Mismatched parentheses.\n";
            return;
        }
        ans += st.top();
        st.pop();
    }

    cout << "Postfix Equation = " << ans << endl;
}

int main() {
    infix_to_postfix();
    return 0;
}
