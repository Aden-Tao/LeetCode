#include <bits/stdc++.h>
using std::vector;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

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
                res.back().end = std::max(inter.end, res.back().end);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<Interval> vec = {
        Interval(15,18),
        Interval(8,10),
        Interval(2,6),
        Interval(1,3)
    };
    for (const auto &interval : s.merge(vec)) {
        std::cout << "[" << interval.start << "," << interval.end << "]" << ",";
    }
    return 0;
}