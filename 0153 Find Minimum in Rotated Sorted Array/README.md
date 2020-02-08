## 算法1

**(二分) *O(logn)***

1. 找到数组的中间元素 mid；
2. 如果```中间元素 > 数组第一个元素```，我们需要在``` mid ```右边搜索变化点；
3. 如果```中间元素 < 数组第一个元素```，我们需要在``` mid ```做边搜索变化点；


```CPP
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] > nums.back())
                l = mid + 1;
            else
                r = mid;
        }
        return nums[r];  
    }
};
```