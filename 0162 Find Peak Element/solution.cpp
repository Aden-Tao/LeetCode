#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main(){
    vector<int> nums{1,2,3,1};
    cout << Solution().findPeakElement(nums) << endl;
    return 0;
}