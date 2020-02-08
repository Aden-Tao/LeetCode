## 算法1

**(二分) *O(n)***

观察数组是否是平地<br>
1. 数组```首元素<尾元素```，单调递增，最小元素为首元素;
2. 数组```首元素==尾元素```，这是最坏情况，顺序遍历找到下降位置的元素为最小;
3. 数组```首元素>尾元素```，非单调递增，套用这道题的中等难度相似题的二分查找算法;

```CPP
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
```