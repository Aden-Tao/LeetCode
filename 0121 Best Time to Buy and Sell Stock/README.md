## 算法1

**(贪心)*O(n)***

遍历一次，更新当前最低价格和最高利润。

```CPP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        int res = 0, lowest = prices[0];
        for (int p : prices)
        {
            res = max(res, p - lowest);
            if (p < lowest)  lowest = p;
            
        }
        return res;
    }
};
```