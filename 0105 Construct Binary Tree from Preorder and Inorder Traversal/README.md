## 算法1

**(递归)*O(n)***

递归建立整棵二叉树：先递归创建左右子树，再创建根节点，并让指针指向根节点。

具体步骤：

1. 利用前序遍历找根节点：前序遍历的第一个数就是根节点的值；
2. 在中序遍历中找到根节点的位置*k*,则 *k*左边是左子树的中序遍历，右边是右子树的中序遍历;
3. 假设左子树的中序遍历的长度是 *l*，则在前序遍历中，根节点后面的 *l* 个数，是左子树的前序遍历，剩下的数是右子树的前序遍历；
4. 有了左右子树的前序遍历和中序遍历，我们可以先递归创建出左右子树，然后再创建根节点；

```CPP
class Solution {
public:
    unordered_map<int, int> pos;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = preorder.size();
        for (int i = 0; i < n; i++)  //哈希表保存前序遍历根节点在中序遍历中的位置
            pos[inorder[i]] = i;
        
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
    {
        if (pl > pr)  return NULL;
        
        int val = preorder[pl];
        int k = pos[val];
        int len = k - il;
        
        TreeNode* root = new TreeNode(val);
        root->left = dfs(preorder, inorder, pl + 1, pl + len, il, k - 1);
        root->right = dfs(preorder, inorder, pl + len + 1, pr, k + 1, ir);
        return root;
    }
};
```