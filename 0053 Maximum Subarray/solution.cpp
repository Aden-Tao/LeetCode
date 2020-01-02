#include <bits/stdc++.h>
using std:: vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> f(nums.size());
        f[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i ++)
        {
            f[i] = std::max(f[i - 1] + nums[i], nums[i]);
            res = std::max(res, f[i]);
        }
        
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec{-2,1,-3,4,-1,2,1,-5,4};
    assert(s.maxSubArray(vec) == 6);
    return 0;
}