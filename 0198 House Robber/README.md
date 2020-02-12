## 算法1

**(动态规划)*O(n)***

1. 令f[i]表示盗窃了第i个房间所能得到的最大收益，g[i]表示不盗窃第i个房间所能得到的最大收益;
2. f[i] = g[i - 1] + nums[i]，g[i] = max(f[i - 1], g[i - 1]);
3. 初始值f[0] = 0, g[0] = 0，答案为max(f[n - 1], g[n - 1]);

```CPP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return 0;
        vector<int> f(n + 1, 0), g(n + 1, 0);
        for (int i = 1; i <= n; i ++)
        {
            g[i] = max (g[i - 1], f[i - 1]);
            f[i] = g[i - 1] + nums[i - 1];
        }
        
        return max(f[n], g[n]);
    }
};
```