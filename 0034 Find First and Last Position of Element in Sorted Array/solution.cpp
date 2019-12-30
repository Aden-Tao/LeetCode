#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty())  return {-1, -1};
        
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        
        if (nums[l] != target)
            return {-1, -1};
        int start = l;
        
        l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        int end = r;
        
        return {start, end};
    }
};

int main(){
    std::vector<int> vec{5,7,7,8,8,10};
    std::vector<int> res = Solution().searchRange(vec, 8);
    for (int n : res)
        std::cout << n << " ";
    return 0;
}