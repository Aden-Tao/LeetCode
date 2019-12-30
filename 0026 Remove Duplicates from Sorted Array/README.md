## 算法1

**(双指针移动)*O(n)***

1. 如果nums的长度是0，直接返回0;
2. 初始令pos为0，i从位置1开始遍历，若发现nums[i]和nums[pos]不相等，则说明找到新的元素，并且nums[++pos]赋值为nums[i];
3. i向后移动直到末尾;

```CPP
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i < n; i ++)
        {
            if (!i || nums[i] != nums[pos - 1])
                nums[pos ++] = nums[i];
        }
        return pos;
    }
};
```