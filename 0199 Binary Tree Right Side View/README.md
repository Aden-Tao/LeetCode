## 算法1

**(深度优先遍历)*O(n)***

在深度优先搜索中，我们总是先访问右子树。这样就保证了当我们访问树的某个特定深度时，我们正在访问的节点总是该深度的最右侧节点。于是，可以存储在每个深度访问的第一个结点，一旦我们知道了树的层数，就可以得到最终的结果数组。

```CPP
class Solution {
public:
    vector<int> res;

    vector<int> rightSideView(TreeNode* root) {
        if (!root)  return res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int level, vector<int>& res)
    {
        if (!root)  return;
        if (level == res.size())  
            res.push_back(root -> val);
        dfs(root -> right, level + 1, res);
        dfs(root -> left, level + 1, res);
    }
};
```