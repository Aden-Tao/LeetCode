## 算法1

**(位运算)*O(1)***

使用位运算 n >> i & 1 可以取出 nn 的第 ii 位二进制数。
我们从小到大依次取出 nn 的所有二进制位，然后逆序累加到另一个无符号整数中。

```CPP
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i ++){
            res <<= 1;
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
};
```