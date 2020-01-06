## 算法1

**(回溯)*O($C^{k}_{n}$)***

回溯函数如下：
1. 若组合数达到了 k 则加入结果集合；
2. 继续按序加入数字，递归；
3. 将 i 从 cur 中移除，实现回溯；

```CPP
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combine(int n, int k) {

        dfs(n, k, 1);
        return res;
    }
    
private:
    void dfs(int n, int k, int idx){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        for(int i = idx; i <= n; i ++){
            cur.push_back(i);
            dfs(n, k, i + 1);
            cur.pop_back();
        }
    }
};
```
