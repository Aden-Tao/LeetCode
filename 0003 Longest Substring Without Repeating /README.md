## 算法1

**(双指针扫描) O(n)**

维护两个指针*i, j(i <= j)*, 表示当前扫描到的子串为 *[i, j]* , 扫描过程中维护一个哈希表 

**CPP代码**
``` CPP
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j ++)
        {
            hash[s[j]] ++;
            while (hash[s[j]] > 1)
                hash[s[i++]] --;
            res = max(res, j - i + 1);
        }
        return res;
    }
};
```

**Python代码**
``` Python
class Solution:
    def lengthOfLongestSubstring(self, s):
        dic, res, start, = {}, 0, 0
        for i, ch in enumerate(s):
            if ch in dic:
                res = max(res, i-start)
                start = max(start, dic[ch]+1)
            dic[ch] = i
        return max(res, len(s)-start)
```