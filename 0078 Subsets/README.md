## 算法1

**(集合的二进制表示)*O($2^{n}$n)***

假设集合大小是 n，我们枚举 0 … $2^{n}$−1 一共 $2^{n}$ 个数。
每个数表示一个子集，假设这个数的二进制表示的第 i 位是1，则表示该子集包含第 i 个数，否则表示不包含。

```CPP
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int subset_num = pow(2, n);
        vector<vector<int> > subset (subset_num, vector<int>());
        
        for (auto i = 0; i < n; i ++){
            for (auto j = 0; j < subset_num; j ++){
                if ((j >> i) & 1)
                    subset[j].push_back(nums[i]);
            }
        }
        return subset;
    }
};
```

## 算法2

从后遍历，遇到一个数就把所有子集加上该数形成新的子集，遍历完毕就是所有子集。

```CPP
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i ++)
        {
            int size = res.size();
            for (int j = 0; j < size; j ++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }   
        return res;
    }
};
```

```Python
class Solution(object):
    def subsets(self, nums):
        res = [[]]
        for i in range(len(nums) - 1, -1, -1):
            for subres in res[:]: res.append(subres+[nums[i]])
    
        return res
```