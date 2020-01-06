## 算法1

**(递归，回溯)*O(n$2^{n}$)***

相比于[Subsets](../0078&#32;Subsets/README.md)多了去重步骤，首先先排序，递归时判断是否和上一个数字相同，相同则跳过。

```CPP
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        
        return res;
    }
    
    void dfs(vector<int> &nums, int s)
    {
        res.push_back(cur);
        for (int i = s; i < nums.size(); i ++)
        {
            cur.push_back(nums[i]);
            dfs(nums, i + 1);
            cur.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])  i++;
        }
    }
};
```

## 算法2

根据 [Subsets](../0078&#32;Subsets/README.md) 解法2<br>
当有重复数字的时候，我们只考虑上一步的新解，算法中用一个指针保存每一步的新解开始的位置即可.<br>
[具体](https://leetcode-cn.com/problems/subsets-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-19/)

```CPP
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty())  return {};
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        
        int size = 1, last = nums[0];
        for (int i = 0; i < nums.size(); i ++)
        {
            if (last != nums[i])
            {
                last = nums[i];
                size = res.size();
            }
            
            int totalSize = res.size();
            for (int j = totalSize - size; j < totalSize; j ++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        
        return res;
    }
};
```