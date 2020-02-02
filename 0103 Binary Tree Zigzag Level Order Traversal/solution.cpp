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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        
        while (q.size())
        {
            vector<int> cur;
            int size = q.size();
            for (int i = 0; i < size; i ++)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p -> left)  q.push(p -> left);
                if (p -> right) q.push(p -> right);
                cur.push_back(p -> val);
            }
            if (level & 1)
                reverse(cur.begin(), cur.end());
            res.push_back(cur);
            level ++;
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
	vector<vector<int>> res = s.zigzagLevelOrder(&root);
    for (auto v : res)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }
    
	return 0;
}