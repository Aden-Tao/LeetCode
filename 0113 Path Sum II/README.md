## 算法1

**(递归)*O($n^2$)***

递归，自顶向下从根节点往叶节点走，每走过一个节点，就让 sum 减去该节点的值，则如果走到某个叶节点时，sum 恰好为0，则说明从根节点到这个叶节点的路径上的数的和等于 sum，此时需要把这条路径记录下来。

```CPP
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)  return res;
        dfs(root, sum);
        return res;
    }

    void dfs(TreeNode* root, int sum)
    {
        if (!root)  return;
        path.push_back(root -> val);
        if (!root->left && !root->right && root->val == sum)
            res.push_back(path);
        if (root->left)  dfs(root->left, sum - root->val);
        if (root->right) dfs(root->right, sum - root->val);
        path.pop_back();
    }
};
```