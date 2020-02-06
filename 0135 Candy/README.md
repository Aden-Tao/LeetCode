## 算法1

**(前向扫描+后向扫描) *O(n)***

1.初始化一个糖果列表，给每个孩子初始化1个糖果；<br>
2.从左往右，如果当前的孩子比左边孩子优秀，他的糖果比前面的多1；<br>
3.从右往左，如果当前孩子比右边孩子优秀，他的糖果比右边至少多1;<br>
4.对糖果列表求和。

```CPP
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> f(n, 1);

        for (int i = 1; i < n; i ++)
            if (ratings[i - 1] < ratings[i])
                f[i] = f[i - 1] + 1;
        for (int i = n - 2; i >= 0; i --)
            if (ratings[i] > ratings[i + 1] && f[i] <= f[i + 1])
                f[i] = f[i + 1] + 1;

        int res = 0;
        for (int n : f) res += n;
        return res;
    }
};
```

```Python
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        res = [1] * len(ratings)
        
        for i in range(1, len(ratings)):
            if ratings[i-1] < ratings[i]:
                res[i] = res[i-1] + 1
        
        for i in range(len(ratings)-1, 0, -1):
            if ratings[i-1] > ratings[i] and res[i-1] <= res[i]:
                res[i-1] = res[i] + 1
        
        return sum(res)
```