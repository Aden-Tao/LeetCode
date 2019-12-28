## 算法1

**(三重枚举，无重复构造) O($n^{3}$)**

完全基于 3Sum 算法的思路，排序后再增加一重循环即可, 配合一些剪枝操作。

```CPP
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        const int size = nums.size();
        vector<int> triplet;
        for(auto i = 0; i < size - 3; i ++){
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;
            for (auto j = i + 1; j < size - 2; ++ j){
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target) continue;
                
                int front = j + 1;
                int back = size - 1;
                while(front < back){
                    int sum = nums[i] + nums[j] + nums[front] + nums[back];
                    if (sum < target)
                        front ++;
                    else if (sum > target)
                        back --;
                    else{
                        triplet = { nums[i], nums[j], nums[front], nums[back] };
                        res.push_back(triplet);
                        while(front < back && nums[front] == triplet[2]) front ++;
                        while(front < back && nums[back]  == triplet[3])  back --;
                    }
                }
                while(j + 1 < size && nums[j + 1]==nums[j]) ++ j;
            }
            while(i + 1 < size && nums[i + 1]==nums[i]) ++ i;
        }
        return res;
    }
};
```