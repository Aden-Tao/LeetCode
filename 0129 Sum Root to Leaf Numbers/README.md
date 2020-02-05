## 算法1 

**(树的遍历) *O(n)***

从根节点递归遍历整棵树，遍历时维护从根节点到该节点的路径表示的数，当遍历到叶节点时，将路径表示的数累加到答案中。

```CPP
class Solution {
public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if (!root)  return res;
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* p, int s)
    {
        if (!p)  return ;
        s = s * 10 + p -> val;
        if (p -> left)  dfs(p -> left, s);
        if (p -> right) dfs(p -> right, s);
        if (!p -> left && !p -> right)
            res += s;
        return;
    }
};
```