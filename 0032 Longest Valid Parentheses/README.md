## 算法1


**(两次线性扫描,贪心)*O(n)***

1. 假设当前从前到后统计合法括号子串，令 ( 的权值为 1，) 的权值为 -1。首先记录 start 为某个起点，则在 i 向后移动的过程中，若当前 [start,i] 区间和等于 0，该字符串是合法的，更新答案；若区间和大于 0，则说明目前缺少右括号，可以不修改 start；若区间和小于 0，则说明区间已经不合法了，需要修正 start 为 i+1。初始时 start 从 0 开始即可。
2. 可是对于 ...((((合法)((( 这种情况，以上算法不能够准确捕捉到最长的合法子串，此时我们逆向考虑，将以上过程反向，从后向前统计，即可处理所有的情况。

```CPP
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), cnt = 0, head = 0;
        int res = 0;
        for (int i = 0; i < n; i ++)
        {
            if (s[i] == '(')  cnt ++;
            else  cnt --;
            if (cnt < 0)
            {
                cnt = 0;
                head = i + 1;
            }
            else if (cnt == 0)
                res = max(res, i - head + 1);
        }
        head = n - 1, cnt = 0;
        for (int i = n - 1; i >= 0; i --)
        {
            if (s[i] == ')')  cnt ++;
            else  cnt --;
            if (cnt < 0)
            {
                cnt = 0;
                head = i - 1;
            }
            else if (cnt == 0)
                res = max(res, head - i + 1);
        }
        return res;
    }
};
```

## 算法2

**(用栈)*O(n)***

1. 用栈维护当前待匹配的左括号的位置。同时用 start 记录一个新的可能合法的子串的起始位置。初始设为 0。
2. 遇到左括号，当前位置进栈。
3. 遇到右括号，如果当前栈不空，则当前栈顶出栈。出栈后，如果栈为空，则用更新答案 i - start + 1；否则更新答案 i - st.top()。
4. 遇到右括号且当前栈为空，则当前的 start 开始的子串不再可能为合法子串了，下一个合法子串的起始位置是 i + 1，更新 start = i + 1。

```CPP
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;

        int start = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (!st.empty()) {
                    st.pop();
                    if (st.empty())
                        ans = max(ans, i - start + 1);
                    else
                        ans = max(ans, i - st.top());
                } else {
                    start = i + 1;
                }
            }
        }

        return ans;
    }
};
```