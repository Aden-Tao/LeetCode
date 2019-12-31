#include <bits/stdc++.h>
using std::vector;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        
        return res;
    }
    
private:
    void dfs(vector<int>& c, int t, int s){
        if (t == 0)
            res.push_back(cur);
        
        for (int i = s; i<c.size(); i++){
            if (c[i] > t)    break;
            if (i != s && c[i] == c[i - 1])  continue;
            cur.push_back(c[i]);
            dfs(c, t - c[i], i + 1);
            cur.pop_back();
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{10,1,2,7,6,1,5};
    for (const auto &v : s.combinationSum2(vec, 8)) {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}
