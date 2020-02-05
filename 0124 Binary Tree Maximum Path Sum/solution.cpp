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
    int res = INT_MIN;
    
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return res;
    }
    
    //从当前点往下走的最大值
    int dfs(TreeNode* root)
    {
        if (!root)  return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 判断在该节点包含左右子树的路径和是否大于当前最大路径和
        res = max(res, left + root -> val + right);
        return max(0, root -> val + max(left, right));
    }
};

int main(){
    TreeNode root(-10);
	TreeNode t2(9);
	TreeNode t3(20);
	TreeNode t4(15);
	TreeNode t5(7);
    
	root.left = &t2;
	root.right = &t3;
	t3.left = &t4;
    t4.right = &t5;

    cout << Solution().maxPathSum(&root) << endl;
    return 0;
}