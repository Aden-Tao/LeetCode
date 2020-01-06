## 算法1

**(滑动窗口)*O(n)***

用哈希表统计出 *T* 中所有字符出现的次数, 然后用两个指针 *i, j (i >= j)*来扫描整个字符串, 快指针往前走遇到 *T* 中字符则哈希表对应计数减一，所需总数减一。 当计数为0时表示所有*T*中字符都在S[i, j]之中，更新比较res, 然后慢指针往前走，如果哈希表对应字符数为0，则总计数加一。

```CPP
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hh;
        
        for(char c : t)  hh[c] ++;
        
        int tot = t.size();
        int l = 0, r = 0;
        int len = INT_MAX, head;
        
        while (r < s.size())
        {
            if (hh[s[r ++]] -- > 0)
                tot --;
            while (tot == 0)
            {
                if (r - l < len)
                {
                    len = r - l;
                    head = l;
                }
                
                if (hh[s[l ++]] ++ == 0)
                    tot ++;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};
```