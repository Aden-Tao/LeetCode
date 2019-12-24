## 算法1

**(中心扩展法) O($n^2$)**

由于字符串长度小于1000，因此我们可以用O($n^2$)的算法枚举所有可能的情况。<br>

- 回文串长度是奇数，依次判断 *s[i - k] == s[i + k], k = 0, 1, 2, ... 
- 回文串长度是偶数数，依次判断 *s[i - k] == s[i + k + 1], k = 0, 1, 2, ... <br>

```CPP
class Solution {
public:
    string longestPalindrome(string s) 
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            //最长回文子串长度为奇数
            for (int j = i, k = i; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
                if (res.size() < k - j + 1)
                    res = s.substr(j, k - j + 1);
            
            //最长回文子串长度为偶数
            for (int j = i, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
                if (res.size() < k - j + 1)
                    res = s.substr(j, k - j + 1);
        }
        
        return res;
    }
};
```

## 算法2 

**(动态规划) O($n^2$)**

中心扩展法不普适，Manacher更不普适，动态规划相对来说更合适一些<br>

DP用于解决“最优子结构”问题:<br>
1. 定义“状态”,这里是一个二维数组dp[l][r]表示子串s[l,r]是否构成闭区间；
2. 找到“状态转移方程”，基于这样一个想法，当s[l]==s[r]时，dp[l][r]的值由dp[l + 1][r - 1]来决定，即当左右边界字符串相等时，整个字符串是否是回文由“原字符串去掉左右边界”的子串是否回文来决定。当原字符串个数小于等于3时，如果左右边界相等那么去掉边界后一定是回文。<br>
    状态转移方程如下:
    ```
    dp[l, r] = (s[l] == s[r] and (r - l <= 2 or dp[l + 1, r - 1]))
    ```

```Python
class Solution:
    def longestPalindrome(self, s):
        n = len(s)
        if n <= 1:
            return s
        
        dp = [[False for _ in range(n)] for _ in range(n)]
        
        res = s[0]
        for r in range(1, n):
            for l in range(r):
                if s[l] == s[r] and (r - l <= 2 or dp[l + 1][r - 1]):
                    dp[l][r] = True
                    if (r - l + 1) > len(res):
```
