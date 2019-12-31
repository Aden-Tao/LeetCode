## 算法1

**(哈希表)*O(NLlogL)***, N 是字符串个数， L 是字符串平均长度， 哈希表和 vector 的插入操作都是 *O(1)*, 排序复杂夫是 *O(LlogL)*

1. 定义从 ```string``` 映射到 ```vector<string>``` 的哈希表: ```unordered_map<string, vector<string>> ```;
2. 将每个字符串的所有字符从小到大排序，将排序好的字符串作为 key， 然后将原字符串插入 key 对应的```vector<string>```中；
   
```CPP
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;
        for (string s: strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto item: mp)
            res.push_back(item.second);
        return res;
    }
};
```

```Python
class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = collections.defaultdict(list)
        for s in strs:
            res[tuple(sorted(s))].append(s)
        return list(res.values())
```