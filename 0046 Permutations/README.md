## 算法1

**(回溯)*O(n x n!)***

从前往后，一位一位枚举，每次选择一个没有被使用过的数。选好之后，将该数的状态改成“已经被使用”，同时将数记录在相应位置上，然后递归。递归返回时，需要将该数的状态改成“未被使用”；

时间复杂度分析：

* 搜索树中最后一层共 ```n!``` 个叶节点，在叶节点处记录方案的计算量是 ```O(n)```，所以叶节点处的计算量是 ```O(n×n!)```。
* 搜索树一共有 ```n!+n!2!+n!3!+…=n!(1+12!+13!+…)≤n!(1+12+14+18+…)=2n!``` 个内部节点，在每个内部节点内均会```for```循环 ```n``` 次，因此内部节点的计算量也是 ```O(n×n!)```。 所以总时间复杂度是 ```O(n×n!)```。

```CPP
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> use;
    
    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++)
            use.push_back(false);
        dfs(nums, 0);
        return res;
    }
    
private:
    void dfs(vector<int> nums, int start){
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i ++){
            if (use[i])  continue;
            use[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, start + 1);
            cur.pop_back();
            use[i] = false;
        }
    }
};
```

```CPP
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permutations(nums, 0, res);
        return res;
    }
    
private:
    void permutations(vector<int>& nums, int begin, vector<vector<int>>& res){
        if (begin==nums.size()){
            res.push_back(nums);
            return;
        }
        for(auto i=begin; i<nums.size(); i++){
            swap(nums[begin], nums[i]);
            permutations(nums, begin+1, res);
            swap(nums[begin], nums[i]);
        }
    }

};
```