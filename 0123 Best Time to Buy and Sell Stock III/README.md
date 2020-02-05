## 算法1

**(线性扫描)*O(n)***

动态规划法。以第i天为分界线，计算第i天之前进行一次交易的最大收益preProfit[i]，和第i天之后进行一次交易的最大收益postProfit[i]，最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤ i≤ n-1)就是最大收益。第i天之前和第i天之后进行一次的最大收益求法同[Best Time to Buy and Sell Stock](../0121%20Best%20Time%20to%20Buy%20and%20Sell%20Stock/README.md)。

```CPP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n)  return 0;
        vector<int> f(n, 0);
        
        int preMin = INT_MAX;
        for (int i = 0; i < n; i ++)
        {
            if (i)  f[i] = f[i - 1];
            if (prices[i] > preMin)
                f[i] = max(f[i], prices[i] - preMin);
            preMin = min(preMin, prices[i]);
        }
        
        vector<int> g(n, 0);
        int postMax = INT_MIN;
        for (int i = n - 1; i >= 0; i --)
        {
            if (prices[i] < postMax)
                g[i] = max(g[i], postMax - prices[i]);
            postMax = max(postMax, prices[i]);
        }
        
        int res  = 0;
        for (int i = 0; i < n; i ++)
            res = max(res, f[i] + g[i]);
        return res;
    }
};
```