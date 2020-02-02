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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (q.size())
        {
            int len = q.size();
            vector<int> cur;
            
            for(int i = 0; i < len; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                cur.push_back(t->val);
                if (t->left)  q.push(t->left);
                if (t->right) q.push(t->right);
            }
            
            res.push_back(cur);
        }
        return res;
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
	vector<vector<int>> res = s.levelOrder(&root);
    for (auto v : res)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
    
	return 0;
}