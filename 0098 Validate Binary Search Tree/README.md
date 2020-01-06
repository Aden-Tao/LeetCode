## 算法1

**(深度优先遍历)*O(n)***

首先将结点的值与上界和下界（如果有）比较。然后，对左子树和右子树递归进行该过程。

```CPP
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return dfs(root, INT_MIN, INT_MAX);
    }
    
    bool dfs(TreeNode *root, long long minv, long long maxv)
    {
        if (!root)  return true;
        if (root->val < minv || root->val > maxv)
            return false;
        
        return dfs(root->left, minv, root->val - 1ll) && dfs(root->right, root->val + 1ll, maxv);
    }
};
```

## 算法2

**(中序遍历)*O(n)***

对于二叉搜索树而言，每个元素都应该比下一个元素小，否则就不是合法的二叉搜索树。

```CPP
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        if (root == NULL)  return true;
        stack<TreeNode*> s;
        TreeNode* pre = NULL;
        
        while (root != NULL || s.size())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            if (pre != NULL && pre->val >= root->val)
                return false;
            
            pre = root;
            root = root->right;
        }
        return true;
    }
};
```