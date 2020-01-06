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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return vector<TreeNode*>();
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r)
    {
        vector<TreeNode*>res;
        if (l > r)
        {
            res.push_back(NULL);
            return res;
        }
        for (int i = l; i <= r; i ++ )
        {
            vector<TreeNode*>left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto &lc : left)
                for (auto &rc : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lc;
                    root->right = rc;
                    res.push_back(root);
                }
        }
        return res;
    }
};

void print_bfs(TreeNode* p)
{
    if (!p) return;
    std::vector<std::string> retv;
    std::queue<TreeNode *> q;
    q.push(p);
    do {
        TreeNode *node = q.front(); q.pop();
        if (node) 
            retv.push_back(std::to_string(node->val));
        else {
            retv.push_back("#");
            continue;
        }
        q.push(node->left); 
        q.push(node->right);
    } while (!q.empty());
    
    auto found = std::find_if(retv.rbegin(), retv.rend(), [](const std::string &s){ return s != "#"; });
    retv.erase(found.base(), retv.end());
    for (const auto &s : retv)
        std::cout << s << ",";
    std::cout << "\b " << std::endl; 
}

int main()
{
    Solution s;
    for (auto p : s.generateTrees(3))
        print_bfs(p);
} 