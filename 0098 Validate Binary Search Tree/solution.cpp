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

int main(){
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);

    node2 -> left = node1;
    node2 -> right = node3;

    assert(Solution().isValidBST(node2) == true);   

    return 0;
}