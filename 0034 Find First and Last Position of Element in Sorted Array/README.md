## 算法1

**(两次二分)*O(logn)***

1. 第一次二分查找第一个位置使得它的值 **大于等于** ```target```, 若该位置的值不等于 ```target```，返回[-1, -1]
;
2. 第二次二分查找第一个位置使得它的值 **大于** ```target```；


```CPP
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
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
```

```Java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1, -1};
        if(nums.length == 0)
            return res;
        int i = 0, j = nums.length - 1;
        //Search for the left one, lower_bound
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] < target)
                i = mid + 1;
            else
                j = mid;
        }
        
        if(nums[i] != target)
            return res;
        else
            res[0] = i;
        
        //Search for the right one, upper_bound - 1
        i = 0;
        j = nums.length - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] > target)
                j = mid;
            else
                i = mid + 1;
        }
        if(nums[j] != nums[res[0]])  //如果target不止一个
            res[1] = j - 1;
        else        //如果target只有一个
            res[1] = i;
        return res;
    }
}
```