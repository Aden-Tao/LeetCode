## 算法1

**(动态规划)*O(n)***

1. 设```f[i]```表示第 ```i``` 个数字为结尾的最大连续子序列的 和 是多少；
2. 初始化 ```f[0] = nums[0]```;
3. 状态转移方程 ```f[i] = max(f[i - 1]+nums[i], nums[i])```,可以视作两种决策，一种是将第```i```个数字和前边的数字拼接起来；另一种是第```i```数字单独视作一个子序列的开始；
4. 最终答案 ```res = max(f[k]), 0 <= k < n;

```CPP
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> f(nums.size());
        f[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i ++)
        {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            res = max(res, f[i]);
        }
        
        return res;
    }
};
```