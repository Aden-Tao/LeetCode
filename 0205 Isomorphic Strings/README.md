## 算法1

**(哈希)*O(n)***

判断字母之间是否一一对应，即判断 s 中的相同字母是否对应到 t 中的相同字母，且 t 中的相同字母是否对应到 s 中的相同字母。

```CPP
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int ms[256] = {0}, mt[256] = {0}, n = s.size();
        
        for(int i = 0; i<n; i++){
            if(ms[s[i]] != mt[t[i]])
                return false;
            ms[s[i]] = i + 1;
            mt[t[i]] = i + 1;
        }
        
        return true;
    }
};
```