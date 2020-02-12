#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(){
    vector<int> nums{1,2,3,4,5,6,7};
    Solution().rotate(nums, 3);
    for (int n : nums)
        cout << n << " ";
    return 0;
}