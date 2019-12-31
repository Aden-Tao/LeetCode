## 算法1

**(递归枚举)**

1. 类似上一题做法，不过本题数字不允许重复；
2. 此题需要排序，目的是去重；
3. 去重的方法是，搜索时如果不想要当前层的数字，则需要找到下一个与之不同的数字才可以进行下一层搜索；在递归函数中增加条件：```if (i > start && num[i] == num[i-1]) continue;``` 无比轻巧的避过了重复项

```CPP
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        
        return res;
    }
    
private:
    void dfs(vector<int>& c, int t, int s){
        if (t == 0)
            res.push_back(cur);
        
        for (int i = s; i < c.size(); i++){
            if (c[i] > t)    break;
            if (i > s && c[i] == c[i - 1])  continue;
            cur.push_back(c[i]);
            dfs(c, t - c[i], i + 1);
            cur.pop_back();
        }
    }
};
```

```Java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(res, new ArrayList<>(), candidates, target, 0);
        return res;
    }
    
    private void dfs(List<List<Integer>> res, List<Integer> cur, int[] candidates, int target, int idx){
        if(target == 0)
            res.add(new ArrayList<>(cur));
        
        for(int i = idx; i < candidates.length; i++){
            if(candidates[i] > target)  return;
            if(i > idx && candidates[i] == candidates[i-1])  continue;  //skip duplicates
            cur.add(candidates[i]);
            dfs(res, cur, candidates, target - candidates[i], i + 1);
            cur.remove(cur.size() - 1);
        }
    }
}
```