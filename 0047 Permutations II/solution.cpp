#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    //引用nums数组需要复位，传入复制nums则不需要
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(!nums.empty())
            dfs(nums, 0, res);
        return res;
    }
    
    void dfs(vector<int> nums, int s, vector<vector<int>>& res){
        if(s==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=s; i<nums.size(); i++){
            if(i!=s && nums[i] == nums[s])  continue;
            swap(nums[s], nums[i]);
            dfs(nums, s+1, res);
        }
    }
};

int main(){
    vector<int> vec{1,1,2};
    for (auto v : Solution().permuteUnique(vec)){
        for (auto n : v)
            std::cout << n << " ";
        std::cout << std::endl;
    }
    return 0;
}
