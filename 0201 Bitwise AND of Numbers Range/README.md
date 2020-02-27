## 算法1

**(位运算)*O(1)***

求前缀，即求出m和n从高位到低位中第一次出现不一样的位置，即可得到答案。

因为出现了第一次不一样之后，从m上升到n的过程中，必定会经历xxx100000...和xxx011111...的一次变化，这次变化会将该位之后的所有数字按位和清零。

```CPP
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        for(; m != n; i++){
            m >>= 1;
            n >>= 1;
        }
        return n << i;
    }
};
```