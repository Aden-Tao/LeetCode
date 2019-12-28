## 算法1

**(迭代)**
1. 预先准备好字典；
2. 第一层循环，是迭代输入字符串；
3. 用两个vector实现前后层迭代替换；

```CPP
class Solution {
public:
    string chars[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return vector<string>();
        
        vector<string> state(1, "");
        for (auto u : digits)
        {
            vector<string> now;
            for (auto c : chars[u - '2'])
                for (auto s : state)
                    now.push_back(s + c);
            state = now;
        }
        return state;
    }
};
```

```Python
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
```