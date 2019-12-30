#include <bits/stdc++.h>

class Solution {
public:
    int search(std::vector<int>& nums, int target) 
    {
        if (nums.empty())  return -1;
        
        //第一步找最小 同153
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back())
                r = mid;
            else
                l = mid + 1;
        }
        
        //通过最小值来二分找target
        if (target <= nums.back())  r = nums.size() - 1;
        else  l = 0, r--;
        
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        
        if (nums[l] == target)  return l;
        return -1;
    }
};

int main(){
    std::vector<int> vec{4,5,6,7,0,1,2};
    assert(Solution().search(vec, 0) == 4);
    assert(Solution().search(vec, 3) == -1);
    return 0;
}