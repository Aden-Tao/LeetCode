#! python3

class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        self.dfs(s, 0, "", res)
        return res
    
    def dfs(self, s, idx, cur, res):
        if idx==4:
            if not s:
                res.append(cur[:-1])
            return
        
        for i in range(1, 4):
            if i <= len(s):
                #choose one digit
                if i == 1: 
                    self.dfs(s[i:], idx+1, cur+s[:i]+".", res)
                #choose two digits, the first one should not be "0"
                elif i == 2 and s[0] != "0": 
                    self.dfs(s[i:], idx+1, cur+s[:i]+".", res)
                #choose three digits, the first one should not be "0", and should less than 256
                elif i == 3 and s[0] != "0" and int(s[:3]) <= 255:
                    self.dfs(s[i:], idx+1, cur+s[:i]+".", res)

if __name__ == "__main__":
    print(Solution().restoreIpAddresses("25525511135"))