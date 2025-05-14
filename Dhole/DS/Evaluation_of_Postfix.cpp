#include <bits/stdc++.h>

using namespace std;

void Evaluation_of_Postfix()
{
    string s;
    cout << "Enter postfix Expression: ";
    cin >> s;

    stack<int> st;
    for (auto c : s)
    {
        if (c >= '0' && c <= '9')
            st.push(c - '0');
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (c == '+')
                st.push(a + b);
            if (c == '-')
                st.push(b - a);
            if (c == '*')
                st.push(a * b);
            if (c == '/')
                st.push(b / a);
        }
    }

    cout << "Evaluation: " << st.top() << endl;
}

int main()
{
    Evaluation_of_Postfix();
    return 0;
}