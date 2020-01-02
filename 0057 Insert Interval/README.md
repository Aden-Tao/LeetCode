## 算法1

**(区间合并)*O(n)***

1. 对于与新区间左右都无交集的区间，直接按序插入；
2. 对于与新区间相交的区间，维护合并后区间的左端点与右端点，最后再将合并后的区间插入合适的位置;


```CPP
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};
        vector<vector<int>> res;
        
        int i = 0;
        
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
            res.push_back(intervals[i ++]);
        
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i ++;
        }
        res.push_back(newInterval);
        
        while (i < intervals.size())
            res.push_back(intervals[i ++]);
        
        return res;
    }
};
```