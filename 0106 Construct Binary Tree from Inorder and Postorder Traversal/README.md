## 算法1

**(递归)*O(n)***

递归建立整棵二叉树：先递归创建左右子树，再创建根节点，并让指针指向根节点。

具体步骤：

1. 利用后序遍历找根节点：后序遍历的最后一个数就是根节点的值；
2. 在中序遍历中找到根节点的位置*k*,则 *k*左边是左子树的中序遍历，右边是右子树的中序遍历;
3. 假设左子树的中序遍历的长度是 *l*，则在后序遍历中，前 *l* 个数就是左子树的后序遍历，接下来的数除了最后一个，就是右子树的后序遍历；
4. 有了左右子树的前序遍历和中序遍历，我们可以先递归创建出左右子树，然后再创建根节点；

```CPP
class Solution {
public:

    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i ++ )
            pos[inorder[i]] = i;
        return dfs(postorder, inorder, 0, n - 1, 0, n - 1);
    }

    // pl, pr 表示当前子树后序遍历在数组中的位置
    // il, ir 表示当前子树中序遍历在数组中的位置
    TreeNode* dfs(vector<int>&post, vector<int>&in, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return NULL;
        int k = pos[post[pr]] - il;
        TreeNode* root = new TreeNode(post[pr]);
        root->left = dfs(post, in, pl, pl + k - 1, il, il + k - 1);
        root->right = dfs(post, in, pl + k, pr - 1, il + k + 1, ir);
        return root;
    }
};
```