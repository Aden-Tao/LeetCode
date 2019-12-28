## 算法1

**(竖向扫描)O(n*m)**

从下标0开始，判断每一个字符串的同一下标是否相等，直到遇到不同的下标

```CPP
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)  return "";
        
        string prefix = strs[0];
        for (int i = 0; i < prefix.size(); i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (i > strs[j].size() - 1 || prefix[i] != strs[j][i])
                    return prefix.substr(0, i);
            }
        }
        return prefix;
    }
};
```


## 算法2

**(横向扫描)O(S)** S是所有字符串中字符数量之和

前两个字符串找公共子串，将其结果与第三个字符串找公共子串，直到公共子串为空或者到达最后一个字符串。

```Python
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
```