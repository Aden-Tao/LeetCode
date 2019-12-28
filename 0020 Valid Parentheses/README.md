## 算法1

**(栈结构)O(n)**

使用栈数据结构:
1. 遇到左括号，压栈；
2. 遇到右括号，判断栈顶是否和当前右括号匹配；若不匹配则返回 *false*,否则弹出栈顶；
3. 最后判断栈是否为空;
   
```CPP
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            }
            else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            }
            else {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
```

```Python
class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:    return True
        stack = []
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            else:
                if stack:
                    t = stack.pop()
                else:
                    return False
                
                if (t, c) in [('(', ')'), ('[', ']'), ('{', '}')]:
                    continue
                else:
                    return False
        
        return len(stack)==0
```