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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = maxDepth(root -> left);
        int r = maxDepth(root -> right);
        return max(l, r) + 1;
    }
};

int main() {
    TreeNode root(3);
	TreeNode t2(9);
	TreeNode t3(20);
	TreeNode t4(15);
	TreeNode t5(7);
	
	root.left = &t2;
	root.right = &t3;
	t3.left = &t4;
	t3.right = &t5;
	
	Solution s;
	cout << s.maxDepth(&root) << endl;
	return 0;
}