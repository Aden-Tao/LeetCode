#include <bits/stdc++.h>
using std::vector;

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
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            i ++;
        }
        res.push_back(newInterval);
        
        while (i < intervals.size())
            res.push_back(intervals[i ++]);
        
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec{
        {1,3},{6,9}
    };
    vector<int> newVec{2,5};
    for (auto v : s.insert(vec, newVec))
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}