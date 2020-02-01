## 算法1

**(递归)*O(n)***

两个子树互为镜像当且仅当：

1. 两个子树根节点相同；
2. 第一棵子树左子树与第二棵子树右子树相同；第一棵子树右子树与第二棵子树左子树相同；

```CPP
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || dfs(root -> left, root -> right);
    }

    bool dfs(TreeNode* p, TreeNode* q)
    {
        if (!p || !q)  return !p && !q;
        return p -> val == q -> val && dfs(p -> left, q -> right) && dfs(p -> right, q -> left);
    }
};
```
