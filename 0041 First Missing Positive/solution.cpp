#include <bits/stdc++.h>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                std::swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; i ++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};

int main(){
    Solution s;
    std::vector<int> vec{3,4,-1,1};
    assert(s.firstMissingPositive(vec) == 2);
    return 0;
}