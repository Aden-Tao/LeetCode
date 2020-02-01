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
    bool isSymmetric(TreeNode* root) {
        return !root || dfs(root -> left, root -> right);
    }

    bool dfs(TreeNode* p, TreeNode* q)
    {
        if (!p || !q)  return !p && !q;
        return p -> val == q -> val && dfs(p -> left, q -> right) && dfs(p -> right, q -> left);
    }
};

int main() {
    TreeNode root(1);
	TreeNode t2(2);
	TreeNode t3(2);
	TreeNode t4(3);
	TreeNode t5(4);
	TreeNode t6(4);
	TreeNode t7(3);
	
	root.left = &t2;
	root.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	
	Solution s;
	std::cout << s.isSymmetric(&root) << std::endl;
    
	return 0;
}