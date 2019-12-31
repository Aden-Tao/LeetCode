## 算法1

**(回溯)*O(n!)***


1. 先将所有数从小到大排序，这样相同的数会排在一起；
2. 为了去重，对于相同的数，我们枚举下一个时从后边第一个不同数开始；
   
```CPP
class Solution {
public:
    //引用nums数组需要复位，传入复制nums则不需要
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(!nums.empty())
            dfs(nums, 0, res);
        return res;
    }
    
    void dfs(vector<int> nums, int s, vector<vector<int>>& res){
        if(s==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=s; i<nums.size(); i++){
            if(i!=s && nums[i] == nums[s])  continue;
            swap(nums[s], nums[i]);
            dfs(nums, s+1, res);
        }
    }
};
```

```Python
class Solution:
    def permuteUnique(self, nums):
        if not nums:
            return nums
        nums.sort()
        def dfs(nums, index):
            if index == len(nums):
                res.append(path+[])
                # return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1] and not visit[i-1]:   # 去重的关键体现处
                    continue
                if not visit[i]:
                    visit[i] = True
                    path.append(nums[i])
                    dfs(nums, index + 1)                    
                    path.pop()
                    visit[i] = False

        path = []
        res = []
        visit = [False for _ in range(len(nums))]
        dfs(nums, 0)
        return res
```