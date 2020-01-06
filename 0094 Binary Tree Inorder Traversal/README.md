## 算法1

**(栈)*O(n)***

中序遍历，左子树先入栈。

```CPP
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode *> s;
        vector<int> res;
        
        while (root || s.size())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top(), s.pop();
            res.push_back(root->val);
            
            root = root->right;
        }
        return res;
    }
    
};
```

```Python
class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # Recursive
        res = []
        self.helper(root, res)
        return res
        
    def helper(self, root, res):
        if not root: return ;
        self.helper(root.left, res)
        res.append(root.val)
        self.helper(root.right, res)
        
```