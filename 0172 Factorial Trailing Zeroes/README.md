## 算法1

**(质数分解)*O(logn)***

由于n!的后缀0是由起质因子2和质因子5相乘而来的，而2的个数总是比5多的，因此我们只需要计算n!中质因子5的个数即可。

```CPP
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n){
            n /= 5;
            res += n;
        }
        
        return res;
    }
};
```