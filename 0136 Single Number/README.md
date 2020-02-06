## 算法1

**(XOR) *O(n)***

1. 两个相同的数字经过异或之后会变为0；
2. 将数组所有元素异或在一起即可得到出现1次的元素值；

```CPP
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto n : nums)
            res ^= n;
        
        return res;
    }
};
```