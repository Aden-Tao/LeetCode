#include <vector>
#include <cassert>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.empty() || nums.back() < target)  return nums.size();
        
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r  >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main(){
    std::vector<int> vec{1,3,5,6};
    assert(Solution().searchInsert(vec, 5) == 2);
    return 0;
}