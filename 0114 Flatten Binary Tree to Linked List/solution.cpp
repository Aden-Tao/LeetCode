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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur)
        {
            if (cur->left)
            {
                TreeNode* tmp = cur->left;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
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

int main() {
    TreeNode root(1);
	TreeNode t2(2);
	TreeNode t3(5);
	TreeNode t4(3);
	TreeNode t5(4);
    TreeNode t6(6);
    
	root.left = &t2;
	root.right = &t3;
	t2.left = &t4;
    t2.right = &t5;
    t3.right = &t6;
	
	Solution s;
    s.flatten(&root);
    
    preOrderPrint(&root);
	return 0;
}
