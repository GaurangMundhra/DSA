#include <bits/stdc++.h>

using namespace std;

int prece(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void infix_to_postfix()
{
    string s;
    cout << "Enter infix equation: ";
    cin >> s;

    stack<char> st;
    string ans = "";

    for (auto c : s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            ans += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prece(c) <= prece(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    cout << "Postfix Equation = " << ans << endl;
}

int main()
{
    infix_to_postfix();
    return 0;
}