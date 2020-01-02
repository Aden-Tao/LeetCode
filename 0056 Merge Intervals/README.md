## 算法1

**(排序)*O(nlogn)***

1. 首先将所有区间按照```start```排序，```start```相同按照```end```排序；
2. 从头开始遍历所有区间，并求他们的并集；
3. 若发现当前遍历到的区间```start```严格大于 ```res```最后的```end```，则当前并集需要加入到答案组中；
4. 若发现当前遍历到的区间```end```严格大于```res```最后的```end```，则更新```res```最后的```end```为当前区间的```end```；


```CPP
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())  return {};
        std::sort(intervals.begin(), intervals.end(), 
                  [](Interval &a, Interval &b){ return a.start < b.start;});
        vector<Interval>  res;
        for(Interval inter: intervals){
            if(res.empty() || inter.start > res.back().end)
                res.push_back(inter);
            else{
                res.back().end = max(inter.end, res.back().end);
            }
        }
        return res;
    }
};
```