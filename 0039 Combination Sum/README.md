## 算法1

**(递归枚举)**

1. 因为可以重复使用数字，在每层搜索中，枚举这个数字添加几次；
2. 搜索的终止条件是当前数字大于目标值或者目标值等于0；
3. 剪枝: 可以将数组从小到大排序，搜索中如果 sum != target 并且 ```sum + condidates[i] > target```，则可以直接终止搜索，因为之后的数字都会比```candidates[i]```大，不会产生答案；

```CPP
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        
        return res;
    }
    
    void dfs(vector<int> & c, int t, int s)
    {
        if (t == 0)
        {
            res.push_back(cur);
            return;
        }
        if (c[s] > t)  return;
        for (int i = s; i < c.size(); i ++)
        {
            cur.push_back(c[i]);
            dfs(c, t - c[i], i);
            cur.pop_back();
        }
    }
};
```

```Java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(list, new ArrayList<>(), candidates, target, 0);
        return list;
    }
    
    private void dfs(List<List<Integer>> list, List<Integer> cur, int[] candidates, int target, int idx){
        if(target == 0){
            list.add(new ArrayList<>(cur));
            return ;
        }
        if(candidates[idx] > target)  return;
        
        for(int i=idx; i<candidates.length; i++){
            cur.add(candidates[i]);
            dfs(list, cur, candidates, target - candidates[i], i); //不是i + 1 因为可以重复用
            cur.remove(cur.size() - 1);
        }
    }
}
```