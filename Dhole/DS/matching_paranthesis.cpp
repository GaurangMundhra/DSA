#include <bits/stdc++.h>

using namespace std;

void balanced_paranthesis()
{
    cout << "Enter String: ";
    string s;
    cin >> s;

    stack<char> st;
    bool flag = true;

    for (auto c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            if (st.empty())
            {
                flag = false;
                break;
            }
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (c == ']')
        {
            if (st.empty())
            {
                flag = false;
                break;
            }
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (c == '}')
        {
            if (st.empty())
            {
                flag = false;
                break;
            }
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
    }

    if (flag && st.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    balanced_paranthesis();
}