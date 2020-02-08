## 算法1

**(二分搜索）*O(logn)***

一般考虑二分搜索。有如下规律：

1. 如果nums[i] > nums[i+1]，则在i之前一定存在峰值元素

2. 如果nums[i] < nums[i+1]，则在i+1之后一定存在峰值元素

```CPP
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
```