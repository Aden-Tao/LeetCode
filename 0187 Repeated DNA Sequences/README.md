## 算法1

**(哈希表)*O(n)***

用哈希表记录所有长度是10的子串的个数。
从前往后扫描，当子串出现第二次时，将其记录在答案中。

```CPP
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        
        vector<string> res;
        for (int i = 0; i + 10 <= s.size(); i ++)
        {
            string str = s.substr(i, 10);
            hash[str] ++;
            if (hash[str] == 2) 
                res.push_back(str);
        }
        return res;
    }
};
```