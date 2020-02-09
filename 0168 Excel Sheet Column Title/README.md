## 算法1

**(进制转换)*O(n)***

10进制转26进制。

```CPP
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        
        while(n){
            n -= 1;
            char tmp = 'A' + n % 26;
            n /= 26;
            res = tmp + res;
        }
        
        return res;
    }
};
```