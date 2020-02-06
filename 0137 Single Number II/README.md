## 算法1

**(位运算) *O(n)***

1. 根据 [Single Number](../0136%20Single%20Number/README.md) 的做法，可以推广到更一般的问题；
2. 考虑二进制每一位上出现 0 和 1 的次数，如果出现 1 的次数为 3k + 1，则证明答案中这一位是 1;
   
```CPP
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int bit = 0; bit < 32; bit ++)
        {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i ++)
                cnt += (nums[i] >> bit) & 1;
            res += (cnt % 3) << bit;
        }
        return res;
    }
};
```