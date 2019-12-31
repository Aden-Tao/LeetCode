#include <bits/stdc++.h>

using std:: vector;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> use;
    
    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++)
            use.push_back(false);
        dfs(nums, 0);
        return res;
    }
    
private:
    void dfs(vector<int> nums, int start){
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i ++){
            if (use[i])  continue;
            use[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, start + 1);
            cur.pop_back();
            use[i] = false;
        }
    }
};

int main(){
    vector<int> vec{1,2,3};
    for (auto v : Solution().permute(vec)){
        for (auto n : v)
            std::cout << n << " ";
        std::cout << std::endl;
    }
    return 0;
}