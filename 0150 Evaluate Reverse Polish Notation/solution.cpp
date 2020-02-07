#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(auto tk: tokens){
            if( isdigit(tk[0]) || tk.size()>1 )  st.push(stoi(tk));
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                switch(tk[0]){
                    case '+': st.push(b + a); break;
                    case '-': st.push(b - a); break;
                    case '*': st.push(b * a); break;
                    case '/': st.push(b / a); break;
                }
            }
        }
        return st.top();
    }
};

int main(){
    vector<string> tokens{"2", "1", "+", "3", "*"};
    cout << Solution().evalRPN(tokens) << endl;
    return 0;
}