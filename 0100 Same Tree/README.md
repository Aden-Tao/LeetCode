## 算法1

**(递归)*O(n)***

递归判断：两个二叉树相等，当且仅当根节点的值相等，且左右两个子树分别相等。

```CPP
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if (p==NULL || q==NULL)
        //     return (p == q);
        // return ( (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right)) );
        
        if(!p && !q)    return true;
        if(!p || !q)    return false;
        if(p->val != q->val)    return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```
