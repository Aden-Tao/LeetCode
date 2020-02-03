## 算法1

**(递归)*O(n)***

对于每个节点：

1. 如果没有子节点，说明是叶节点，则返回1；
2. 如果有子节点，说明是内部结点，则返回子节点的深度的最小值 + 1（加上根节点这层）；

```CPP
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
        
        if (!left || !right)
            return left + right + 1;
        else
            return min(left, right) + 1;
    }
};
```