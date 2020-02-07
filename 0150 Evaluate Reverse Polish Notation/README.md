## 算法1

**(栈操作) *O(n)***

遍历所有元素。如果当前元素是整数，则压入栈；如果是运算符，则将栈顶两个元素弹出做相应运算，再将结果入栈。
最终表达式扫描完后，栈里的数就是结果。

```CPP
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
```