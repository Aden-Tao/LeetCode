## 算法1

**(暴力枚举)*O(n * len)***

1. 假设 s 的长度为 n ，单词的长度为 len ，单词的个数为 tot ;
2. 由于数组中每个单词长度都是相同的，故可以按照单词的长度 len 来将 s 划分为 len 种候选单词序列。举例来看 barfoothefoobarman，根据单词长度为3，可以得到3种不同的划分，分别是bar foo the foo bar man、arf oot hef oob arm an和rfo oth efo oba rma n三种;
3. 对于以上的每一种划分来说，仅需要用 unordered_map 就可以暴力的算出来，能否能由单词列表中的所有单词拼接而成;

```CPP
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty())  return res;
        if (words[0].size() == 0) return res;
        int len = s.size(), n = words.size(), m = words[0].size();
        unordered_map<string, int> mp;
        for (string w : words)
            mp[w] ++;
        
        for (int i = 0; i <= len - n * m; i ++)
        {
            unordered_map<string, int> tmp;
            int j = 0;
            for (; j < n; j ++)
            {
                string st = s.substr(i + j * m, m);
                tmp[st] ++;
                if (!mp[st] || tmp[st] > mp[st])
                    break;
            }
            if (j == n)
                res.push_back(i);
        }
        return res;
    }
};
```