#! python3

class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        self.res = []
        self.dfs(s, [])
        return self.res
    
    def dfs(self, s, cur):
        if not s:
            self.res.append(cur[:])
        
        for i in range(1, len(s)+1):
            if self.isPali(s[:i]):
                cur.append(s[:i])
                self.dfs(s[i:], cur)
                cur.pop()
            
    def isPali(self, s):
        return s == s[::-1]


if __name__ == "__main__":
    print(Solution().partition("aab"))