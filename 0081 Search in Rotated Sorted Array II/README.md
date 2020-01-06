## 算法1

**(二分)*O(n)***

这道题类似于[Search in Rotated Sorted Array](../0033&#32;Search&#32;in&#32;Rotated&#32;Sorted&#32;Array/README.md)，不同点在于这道题里的数组可能包含相同元素。<br>

每次二分，左半部分和右半部分至少有一边是有序的，以此为条件可以分成两种情况：
1. 左半边是有序的<br>
    (1) target落在左半边<br>
    (2) otherwise<br>
2. 右半边是有序的<br>
    (1) target落在右半边<br>
    (2) otherwise<br>
    
综上所述，一共两种可能性，这两种情况各自又有两种可能性，代码如下：

*如果相等的话，说明区间首尾的数可能一样，此时就不能二分了，只能缩小区间范围。这个算法当所有数都相同的时候，时间复杂度是 O(n)*

```CPP
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
```

```Python
```