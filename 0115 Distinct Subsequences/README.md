## 算法1

**(动态规划)*O(nm)***

f[i][j] 表示用 *S* 的前 *i* 个字符匹配 *T* 的前 *j* 个字符的方案数。

初始化：*S*任意字串都可以匹配空字符串，所以 f[i][0] = 1, ∀i∈[0,len(S)];

状态转移：<br>
* 如果 S[i−1]≠T[j−1]，则 S[i−1] 不能匹配 T[j−1]，所以 f[i][j]=f[i−1][j]；
* 如果 S[i−1]=T[j−1]，则 S[i−1] 既可以匹配 T[j−1]，也可以不匹配 T[j−1]，所以 f[i][j]=f[i−1][j]+f[i−1][j−1]；

```CPP
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1));

        for (int i = 0; i <= n; i ++)  f[i][0] = 1;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= m; j ++)
            {
                if (s[i - 1] == t[j - 1])
                    f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
                else
                    f[i][j] = f[i - 1][j];
            }
        }
        return f[n][m];
    }
};
```