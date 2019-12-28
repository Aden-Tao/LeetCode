#! python3

class Solution:
    def longestCommonPrefix(self, str):
        if not str:
            return ""
        res = str[0]
        for i in range(1, len(str)):
            while str[i].find(res) != 0:
                res = res[0: len(res) - 1]
            if not res:
                return ""
            
        return res


if __name__ == "__main__":
    strs = ["flower","flow","flight"]
    print(Solution().longestCommonPrefix(strs) == "fl")