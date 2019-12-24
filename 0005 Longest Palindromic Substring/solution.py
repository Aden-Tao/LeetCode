#!python3

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
                        res = s[l: r + 1]
        return res

if __name__ == "__main__":
    s = Solution()
    print(s.longestPalindrome("abba") == "abba")
    print(Solution().longestPalindrome("babad") == "bab")
    print(Solution().longestPalindrome("cbbd") == "bb")
