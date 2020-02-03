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
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)  return res;
        dfs(root, sum);
        return res;
    }

    void dfs(TreeNode* root, int sum)
    {
        if (!root)  return;
        path.push_back(root -> val);
        if (!root->left && !root->right && root->val == sum)
            res.push_back(path);
        if (root->left)  dfs(root->left, sum - root->val);
        if (root->right) dfs(root->right, sum - root->val);
        path.pop_back();
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
    TreeNode t9(5);
    TreeNode t10(1);
	
	root.left = &t2;
	root.right = &t3;
	t2.left = &t4;
    t3.left = &t5;
    t3.right = &t6;
    t4.left = &t7;
    t4.right = &t8;
    t6.left = &t9;
    t6.right = &t10;
	
	Solution s;
    vector<vector<int>> res = s.pathSum(&root, 22);
    for (auto v : res)
    {
        for (int n : v)
        {
            cout << n << " ";
        }
        cout << endl;
    }
	return 0;
}