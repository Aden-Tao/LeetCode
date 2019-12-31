## 算法1 

**(动态规划)*O(nm)***

1. 状态表示：```dp[i][j]```代表```s```的前```i```个字符和```p```的前```j```个字符是否匹配;

2. 状态初始化：```dp[0][0] = true```，对于```1 <= i <= m```如果```p[i - 1] = '*' && dp[0][i - 1]```那么```dp[0][i] = true```，这对应着```p```以```***as```开头的字符串，因为```*```可以代表```0```个字符，所以可以往后匹配;

3. 状态转移：<br>
```s[i - 1] == p[j - 1] || p[j - 1] == '?'```，这时候是精准匹配，所以取决于```s```的前```i - 1```个字符和```p```的前```j - 1```个字符是否匹配。```dp[i][j] = dp[i - 1][j - 1]```;<br>
```p[j - 1] == '*'```，这个时候*可以代表空串或者任意多个字符;

4. 如果是空串，那么```dp[i][j] = dp[i][j - 1]```
如果不是空串，那么```dp[i][j] = dp[i - 1][j]```。这是因为```*```代表了任意多个字符，如果能匹配前```i - 1```个字符，那么就在```*```代表的字符串后面加上```s[i]```，就可以匹配前```i```个字符啦;

```CPP
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= m; i ++)
            if (p[i - 1] == '*' && dp[0][i - 1])
                dp[0][i] = true;
            else
                break;
        
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
        return dp[n][m];
    }
};
```

```Python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m, n = len(s) + 1, len(p) + 1
        dp = [[False] * n for _ in range(2)]
        dp[0][0] = True
        
        for j in range(1, n):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-1]
                
        col = 0; #前一行
        for i in range(1, m):
            dp[col^1] = [False] * n
            for j in range(1, n):
                if p[j-1] == '?' or p[j-1] == s[i-1]:
                    dp[col^1][j] = dp[col][j-1]
                elif p[j-1] == '*':
                    dp[col^1][j] = dp[col][j] or dp[col][j-1] or dp[col^1][j-1]
            col ^= 1
        
        return dp[col][n-1]
```