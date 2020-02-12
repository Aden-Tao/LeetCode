## 算法1

**(位运算)*O(1)***

每次操作先判断 nn 的最低位是否是1，然后将 nn 右移一位。
总共操作32次。

```CPP
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n)
        {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};
```