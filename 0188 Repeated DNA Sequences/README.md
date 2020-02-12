## 算法1

**(动态规划)*O(nk)***

1. 当 k≥n/2k≥n/2 时，问题转化为了 [Best Time to Buy and Sell Stock II](../0122%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II/README.md) 问题．, 否则，仍然可以采用动态规划思路解决问题;
2. 我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：<BR>
* ```local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)```<BR>
对于局部变量的维护就是看两个量，第一个是全局到i-1天进行j-1次交易，然后加上今天的交易，如果今天是赚钱的话（也就是前面只要j-1次交易，最后一次交易取当前天），第二个量则是取local第i-1天j次交易，然后加上今天的差值（这里因为local[i-1][j]比如包含第i-1天卖出的交易，所以现在变成第i天卖出，并不会增加交易次数，而且这里无论diff是不是大于0都一定要加上，因为否则就不满足local[i][j]必须在最后一天卖出的条件了）

* ```global[i][j] = max(local[i][j], global[i - 1][j])```<BR>
  去当前局部最好的，和过往全局最好的中大的那个（因为最后一次交易如果包含当前天一定在局部最好的里面，否则一定在过往全局最优的里面）

```CPP
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        
        int n = prices.size();
        if (k >= n / 2)  return stock2(prices);
        
        vector<int> local(k + 1);
        vector<int> global(k + 1);
        
        for (int i = 1; i < n; i ++)
        {
            int diff = prices[i] - prices[i - 1];
        
            for (int j = k; j  > 0; j --)
            {
                local[j] = max(global[j - 1], local[j] + diff);
                global[j] = max(global[j], local[j]);

            }
        }
        return global[k];
    }
    
    int stock2(vector<int> &p)
    {
        int res = 0;
        for (int i = 1; i < p.size(); i ++)
            res += max(0, p[i] - p[i - 1]);
        return res;
    }
};                
```