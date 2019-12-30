## 算法1

**(二分检索)*O(logn)***

1. 数组长度为0需要特殊判断;
2. 先二分检索是以哪个元素将数组分割成两部分,具体为:每次二分时，如果 ```nums[mid] >= nums[l] && nums[mid] >= nums[r]```，则 ```l = mid + 1```；如果 ```nums[mid] <= nums[l] && nums[mid] <= nums[r]```，则 ```r = mid```；否则 break。最终数组分为 ```[0, l - 1]``` 和 ```[l, n - 1]```两段区间;
3. 最后在对应区间分别二分找 ```target``` 即可;

```CPP
class Solution {
public:
    int search(vector<int>& nums, int target) 
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
```