#include <iostream> 
#include <stack>
using namespace std;

int priority(char op){
    if(op == '^')return 3;
    if(op == '*' || op == '/')return 2;
    if(op == '+' || op == '-')return 1;
    return 0;
}

int main(){
    stack <char> st;

    string s;
    cout << "Enter the expression to convert it into postfix:";
    getline(cin,s);

    string res= "";
    for(int i = 0 ; i< s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9' ||
            s[i] >='a' && s[i] <= 'z'||
            s[i] >= 'A' && s[i] <= 'Z'){
                res += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res+= st.top();
                st.pop();
            }
            st.pop();
        }
        else {
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
    }
    while(!st.empty()){
            res += st.top();
            st.pop();
        }

        for(int i =0 ; i< res.length() ; i++){
            cout << res[i];
        }
}

