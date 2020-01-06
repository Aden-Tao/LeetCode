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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode *> s;
        vector<int> res;
        
        while (root || s.size())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top(), s.pop();
            res.push_back(root->val);
            
            root = root->right;
        }
        return res;
    }
    
};

int main(int argc, char** argv) {
  TreeNode* root = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
    
  root -> right = node2;
  node2 -> left = node3;
    
  Solution s;
  for (auto i : s.inorderTraversal(root))
    std::cout << i << " ";
  std::cout << std::endl; 
    
  return 0;
}