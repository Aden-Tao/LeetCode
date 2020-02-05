## 算法1

**(递归，树的遍历)*O($n^2$)***

递归遍历整棵树，递归时维护从每个节点开始往下延伸的最大路径和。
对于每个点，递归计算完左右子树后，我们将左右子树维护的两条最大路径，和该点拼接起来，就可以得到以这个点为割点的最大路径。

```CPP
class Solution {
public:
    int res = INT_MIN;
    
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return res;
    }
    
    //从当前点往下走的最大值
    int dfs(TreeNode* root)
    {
        if (!root)  return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 判断在该节点包含左右子树的路径和是否大于当前最大路径和
        res = max(res, left + root -> val + right);
        return max(0, root -> val + max(left, right));
    }
};
```