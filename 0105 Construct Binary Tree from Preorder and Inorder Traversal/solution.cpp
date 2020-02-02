#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

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

void preOrderPrint(TreeNode* root)
{
    if (!root)  cout << "# ";  
    else
    {
        cout << root->val << " ";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }       
}

int main(){
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    TreeNode* root = Solution().buildTree(preorder, inorder);

    preOrderPrint(root);
    return 0;
}