#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else
                r--;
        }
        return nums[l];
    }
};

int main(){
    vector<int> nums{2,2,2,0,1};
    cout << Solution().findMin(nums) << endl;
    return 0;
}