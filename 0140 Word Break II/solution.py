#! python3

class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        words = set(wordDict)
        mem = {}
        
        def wordBreak(s):
            if s in mem:  return mem[s]
            res = []
            if s in words:  res.append(s)
            for i in range(1, len(s)):
                right = s[i:]
                if right not in words:  continue
                res += [w + ' ' + right for w in wordBreak(s[:i])]
            mem[s] = res
            return mem[s]
        
        return wordBreak(s)

if __name__ == "__main__":
    print(Solution().wordBreak("catsanddog", ["cat", "cats", "and", "sand", "dog"]))