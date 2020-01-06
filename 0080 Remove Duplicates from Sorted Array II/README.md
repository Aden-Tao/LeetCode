## 算法1

**(线性扫描)*O(n)***

由于数组有序，所以相同元素一定是相邻的。
我们定义一个指针 k，表示新数组的末尾，然后从前往后扫描原数组，如果当前数不等于 nums[k] 且不等于 nums[k−1]，则将当前数插入新数组的末尾。

```CPP
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int k = 1;
        for (int i = 2; i < nums.size(); i ++ )
            if (nums[i] != nums[k - 1])
                nums[ ++ k] = nums[i];
        k ++ ;
        return k;
    }
};
```

```Python
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for n in nums:
            if i < 2 or n > nums[i - 2]:
                nums[i] = n
                i += 1
        return i
```