#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        if (nums.empty())  return false;
        int l = 0, r = nums.size() - 1;
        
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] == target)  return true;
            //左半有序
            if (nums[mid] > nums[r] )
            {
                if (target < nums[mid] && target >= nums[l])
                    r = mid;
                else
                    l = mid + 1;
            }
            //右半有序
            else if (nums[mid] < nums[r]) 
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
                r--;
        }
        return nums[l] == target ? true: false;
    }
};

int main(){
    Solution s;
    
    vector<int> vec{2,5,6,0,0,1,2};
    assert(s.search(vec, 0) == true);
    assert(s.search(vec, 3) == false);
    return 0;
}