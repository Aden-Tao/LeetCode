#include <bits/stdc++.h>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int g_mx = 0;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (i > g_mx)
                return false;
            g_mx = std::max(g_mx, i + nums[i]);
           
        }
        return true;
    }
};

int main(){
    Solution s;
    std::vector<int> vec{2,3,1,1,4};
    assert(s.canJump(vec) == true);
    return 0;
}