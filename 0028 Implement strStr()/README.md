## 算法1

**(暴力枚举)*O(nm)***

实现strStr()，即返回第一次在haystack中出现子串needle的位置，如果不存在则返回-1, 按照定义，对haystack每个位置暴力匹配子串needle


```CPP
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        int m=haystack.size(), n=needle.size();
        for(int i=0; i<m-n+1; i++){
            for(int j=0; j<n; j++){
                if(haystack[i+j]!=needle[j])
                    break;
                if(j==n-1)
                    return i;
            }
        }
        return -1;
    }
};
```