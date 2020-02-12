#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> res;

    vector<int> rightSideView(TreeNode* root) {
        if (!root)  return res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int level, vector<int>& res)
    {
        if (!root)  return;
        if (level == res.size())  
            res.push_back(root -> val);
        dfs(root -> right, level + 1, res);
        dfs(root -> left, level + 1, res);
    }
};

int main(){

    TreeNode *root = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(4);

    root -> left = n2;
    root -> right = n3;
    n2 -> right = n4;
    n3 -> right = n5;

    vector<int> res = Solution().rightSideView(root);
    
    for (int n : res)
        cout << n << " ";

    return 0;
}