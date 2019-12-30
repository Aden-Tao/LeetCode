## 算法1

**(找规律)*O(n)***

1. 先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
2. 再找出另一个最大索引 l 满足 nums[l] > nums[k]；
3. 交换 nums[l] 和 nums[k]；
4. 最后翻转 nums[k+1:]。

```CPP
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for (int i = n - 2; i >= 0; i --)
        {
            if (nums[i] < nums[i + 1])
            {
                j = i;
                break;
            }
        }
        if (j == -1)
            reverse(nums.begin(), nums.end());
        else
        {
            for (int i = n - 1; i > j; i --)
                if (nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                    break;
                }
            reverse(nums.begin() + j + 1, nums.end());
        }
        return;
    }
};
```