#include <bits/stdc++.h>
using std::vector;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        
        return res;
    }
    
    void dfs(vector<int> & c, int t, int s)
    {
        if (t == 0)
        {
            res.push_back(cur);
            return;
        }
        if (c[s] > t)  return;
        for (int i = s; i < c.size(); i ++)
        {
            cur.push_back(c[i]);
            dfs(c, t - c[i], i);
            cur.pop_back();
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{2,3,6,7};
    for (const auto &v : s.combinationSum(vec, 7)) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}