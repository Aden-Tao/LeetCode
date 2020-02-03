## 算法1

**(递归)*O(n)***

递归，自顶向下从根节点往叶节点走，每走过一个节点，就让 sum 减去该节点的值，则如果走到某个叶节点时，sum 恰好为0，则说明从根节点到这个叶节点的路径上的数的和等于 sum。<br>
只要找到一条满足要求的路径，递归即可返回。

```CPP
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)  return false;
        if (!root -> left && !root -> right)
            return root -> val == sum;
        if (root -> left && hasPathSum(root -> left, sum - root -> val))  return true;
        if (root -> right && hasPathSum(root -> right, sum - root -> val)) return true;
        return false;
    }
};
```