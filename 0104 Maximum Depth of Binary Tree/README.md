## 算法1

**(递归)*O(n)***

递归求解：

当前树的最大深度等于左右子树的最大深度加1。

```CPP
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = maxDepth(root -> left);
        int r = maxDepth(root -> right);
        return max(l, r) + 1;
    }
};
```

## 算法2

**(层次遍历)*O(n)***

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)  return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (q.size())
        {
            ++res;
            int cur = q.size();
            int i = 0;
            while (i < cur)
            {
                ++i;
                root = q.front();
                q.pop();
                if (root -> left)  q.push(root -> left);
                if (root -> right) q.push(root -> right);
            }
        }
        return res;
    }
};
```