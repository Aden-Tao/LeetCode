## 算法1

**(两重枚举)O($n^{2}$)**

类似**3Sum**
1. 先对nums排序,然后固定一层循环 i ;
2. 然后初始 l = i + 1, r = n - 1; 如果```nums[i] + nums[l] + nums[r] == target```则直接返回target；若 ```nums[i] + nums[l] + nums[r] < target```,则 l ++, 否则 r --;
3. 每次更新res 为最接近target的值;

```CPP
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (abs(nums[i] + nums[l] + nums[r] - target) < abs(res - target))
                    res = nums[i] + nums[l] + nums[r];
                if (nums[i] + nums[l] + nums[r] == target)
                    return target;
                else if (nums[i] + nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }
};
```