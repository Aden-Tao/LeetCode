## 算法1

**(快速幂)*O(logn)***

1. 将 n 进行二进制拆分， 若 n 的二进制位第 k 位是 1， 则 res 可以乘上 $x^{2^{k}}$;
2. 计算$x^{2^{k}}$ 时只需每次将自身做平方；

```CPP
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n; i != 0; i /= 2){
            if(i % 2 != 0){
                res *= x;
            }
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
```