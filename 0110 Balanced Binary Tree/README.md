## 算法1

**(递归)*O(n)***

递归判断：
先递归判断两棵子树是否是平衡的，递归的过程中记录每棵树的最大深度值，然后判断两棵子树的最大深度的差是否不大于1。

```CPP
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)  return true;
        return dfs(root) != -1;
    }

    int dfs(TreeNode* p)
    {
        if (!p)  return 0;
        int left = dfs(p -> left);
        int right = dfs(p -> right);

        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
    }
};
```