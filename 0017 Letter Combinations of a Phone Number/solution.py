#! python3

class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        
        self.dict = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs","8":"tuv","9":"wxyz",}
        res = ['']
        for digit in digits:
            res = [a + b for a in res for b in self.dict[digit]]
                
        return res

if __name__ == "__main__":
    print(Solution().letterCombinations("23"))