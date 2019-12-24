#! python3

class Solution:
    def isMatch(self, s, p):
        if not p:
             return not s
        first = bool(s) and p[0] in {s[0], '.'}
        if len(p) >= 2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or first and self.isMatch(s[1:], p)
        else:
            return first and self.isMatch(s[1:], p[1:])

if __name__ == "__main__":
    
    print(Solution().isMatch("aa", "a") == False)
    print(Solution().isMatch("aa", "a*") == True)
    print(Solution().isMatch("mississippi", "mis*is*p*.") == False)
