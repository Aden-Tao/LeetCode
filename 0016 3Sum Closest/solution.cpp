#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (abs(nums[i] + nums[l] + nums[r] - target) < abs(res - target))
                    res = nums[i] + nums[l] + nums[r];
                if (nums[i] + nums[l] + nums[r] == target)
                    return target;
                else if (nums[i] + nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec{-1, 2, 1, -4};
    assert(s.threeSumClosest(vec, 1) == 2);
    return 0;
}