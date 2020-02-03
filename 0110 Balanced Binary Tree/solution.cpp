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
    bool isBalanced(TreeNode* root) {
        if (!root)  return true;
        return dfs(root) != -1;
    }

    int dfs(TreeNode* p)
    {
        if (!p)  return 0;
        int left = dfs(p -> left);
        int right = dfs(p -> right);

        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
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
    assert(s.isBalanced(&root) == true);
    
	return 0;
}