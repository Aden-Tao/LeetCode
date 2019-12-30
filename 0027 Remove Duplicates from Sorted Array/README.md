## 算法1

**(双指针移动)*O(n)***

类似26题
只需要每次判断 nums[i] 与 val 是否相同；若相同，则 nums[k] 赋值为 nums[i] 并且 k ++

```CPP
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[k++] = nums[i];
        return k;
    }
};
```