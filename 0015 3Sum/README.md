## 算法1

**(两重枚举)O($n^{2}$)**

先对原数组进行排序，然后第一层循环无重复枚举第一个数字，接下来采用两头相向的方式相中间寻找剩下的两个合适数字，具体的:<br>
1. 初始化 l 为 i + 1, r = n - 1;
2. 当 l < r 时，如果当前 ``` nums[l] + nums[r] == target ```则添加答案并同时向后无重复移动 l, 向前无重复移动 r ; 若 ``` nums[l] + nums[r] < target ```则 l ++ , 否则 r -- ；

```CPP
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        for (; i < n - 2; i ++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                if (s == 0)
                {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    l += 1, r -= 1;
                    while (l < r && nums[l] == nums[l - 1])
                        l ++;
                    while (l < r && nums[r] == nums[r + 1])
                        r --;
                }
                else if (s > 0)
                    r --;
                else
                    l ++;
            }
        }
        return res;
    }
};
```