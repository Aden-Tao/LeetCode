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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)  return false;
        if (!root -> left && !root -> right)
            return root -> val == sum;
        if (root -> left && hasPathSum(root -> left, sum - root -> val))  return true;
        if (root -> right && hasPathSum(root -> right, sum - root -> val)) return true;
        return false;
    }
};

int main() {
    TreeNode root(5);
	TreeNode t2(4);
	TreeNode t3(8);
	TreeNode t4(11);
	TreeNode t5(13);
    TreeNode t6(4);
    TreeNode t7(7);
    TreeNode t8(2);
    TreeNode t9(1);
	
	root.left = &t2;
	root.right = &t3;
	t2.left = &t4;
    t3.left = &t5;
    t3.right = &t6;
    t4.left = &t7;
    t4.right = &t8;
    t6.right = &t9;
	
	Solution s;
    assert(s.hasPathSum(&root, 22) == true);
    
	return 0;
}