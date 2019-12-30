## 算法1

**(二分)*O(logn)***

1. 二分查找大于等于目标值的第一个位置;
2. 如果所有元素都小于 ```target``` 返回 ```n```；
3. 如果所有元素都大于 ```target``` 返回 ```0```;

```CPP
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
```