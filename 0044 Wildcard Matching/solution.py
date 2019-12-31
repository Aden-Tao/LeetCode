#! python3

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

if __name__ == "__main__":
    print(Solution().isMatch("cb", "?a"))
    print(Solution().isMatch("adceb", "*a*b"))