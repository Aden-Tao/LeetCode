## 算法1

**(贪心)*O(n)***

从前向后遍历数组，只要当天的价格高于前一天的价格，就算入收益。

```CPP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i ++ )
            res += max(0, prices[i] - prices[i - 1]);
        return res;
    }
};
```