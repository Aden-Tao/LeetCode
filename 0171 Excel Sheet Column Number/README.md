## 算法1

**(进制转换) *O(n)***

逐个读取字符进行转换，本质上是26进制转10进制。
例如，BC=2×26^1+3×26^0=55。

```CPP
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            res += (s[i] - 'A' + 1) * pow(26, s.size() - i - 1);
        }
        
        return res;
    }
};
```