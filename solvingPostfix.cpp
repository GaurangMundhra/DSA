#include <iostream>
#include<stack>
#include <cctype>
using namespace std;

int main(){
    stack <int> st;
    string s;

    cout << "Enter the postfix expression to solve:";
    cin >> s;


    for(int i = 0 ; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');
        }
        else if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-'){
             int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.pop();

            int result = 0;
            switch(s[i]){
                case '*':
                 result =  top2*top1;
                 break;

                case '/': 
                result = top2/top1;
                break;

                case '+': 
                result = top2+top1;
                break;

                case '-': 
                result = top2-top1;
                break;
            }
            st.push(result);
         }
    }
    if(st.size() == 1){
            int result = st.top();
            cout<< result << endl;
         }
         else{
            cout << "Invalid expression" << endl;
         }
    return 0;
}