## 算法1

**(哈希表) *O($n^2$)***

先枚举一个定点，然后将其它点按斜率分组，斜率指与定点连线的斜率，分组可以利用哈希表。由于一个定点加斜率可以唯一确定一条直线，所以被分到同一组的点都在一条直线上。组中点数的最大值就是答案。

特殊情况：

1. 竖直直线不存在斜率，需要单独计数；
2. 与定点重合的点可以被分到所有组中，需要单独处理；

```CPP
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty())  return 0;
        int res = 0;

        for (int i = 0; i < points.size(); i ++)
        {
            unordered_map<long double, int> map;
            int duplicates = 0, verticals = 1;

            for (int j = i + 1; j < points.size(); j ++)
                if (points[i][0] == points[j][0])
                {
                    verticals ++;
                    if (points[i][1] == points[j][1])
                        duplicates ++;
                }
                
            for (int j = i + 1; j < points.size(); j ++)
                if (points[i][0] != points[j][0])
                {
                    long double slope = (long double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    if (map[slope] == 0) map[slope] = 2;
                    else    map[slope] ++;
                    res = max(res, map[slope] + duplicates);
                }
            res = max(res, verticals);
        }
        return res;
    }
};
```