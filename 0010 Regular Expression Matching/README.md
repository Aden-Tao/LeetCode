## 算法1

**(递归)$O((S + P) * 2 ^ (S + P/2))$**

从字符开始比较:<br>
```
if (s == p || (p == '.' && s != '\0'))   //相同字符
```
1. 若p为空，此时返回s是否为空;
2. 定义pre表示s和p第一位是否匹配成功。匹配的条件:s不能为空且p[0]==s[0] or '.';
3. 若p中含有*,条件len(p) >= 2 and p[1] == '*',表示第二位为\*,即有字符和\*相连，对应两种情况：
   - 跳过这两个字符，表示字符出现0次，即*isMatch(s, p[2:])*；
   - 首位匹配成功，继续匹配s[1: ]和p，即*pre and isMatch(s[1:], p)*;
4. 若无*则继续匹配，返回* pre and isMatch(s[1:], p[1:]);

```Python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
             return not s
        first = bool(s) and p[0] in {s[0], '.'}
        if len(p) >= 2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or first and self.isMatch(s[1:], p)
        else:
            return first and self.isMatch(s[1:], p[1:])
```


## 算法2
**动态规范O(SP)**
1. 设状态*f(i,j)*表示字符串*s*前*i*个字符串和字符串*p*的前*j*个字符串是否匹配,这里假设*s*和*p*都从下标1开始。初始值, *f(0,0) = true*。
2. 当*i > 0*且*s\(i\) == p\(j\) || p\(j\) == '\.'* 时， *f(i,j) = f(i,j) || f(i - 1, j -1)*;
3. 当*p\(j\) == '\*'* 时，若*j >= 2 *,* f(i, j)* 可以从*f(i, j - 2)* 转移，表示丢弃这一次的'\*'和它之前的那个字符；若*i > 0* 且*s(i) == p(j - 1)* ,表示这个字符可以利用这个'\*',则可以从*f(i - 1, j)* 转移，表示利用'\*';
4. 初始状态*f(0,0) = true*; 循环枚举*i*从0到n；*j*从*1*到*m*,因为*f(0,j)*有可能是有意义的，需要被转移更新;
5. 输出*f(n,m)*;

```CPP
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        s = " " + s;
        p = " " + p;
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (i > 0 && (s[i] == p[j] || p[j] == '.'))
                    f[i][j] = f[i][j] | f[i - 1][j - 1];
                if (p[j] == '*') {
                    if (j >= 2)
                        f[i][j] = f[i][j] | f[i][j - 2];
                    if (i > 0 && (s[i] == p[j - 1] || p[j - 1] == '.'))
                        f[i][j] = f[i][j] | f[i - 1][j];
                }
            }
        return f[n][m];
    }
};
```