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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)  return vector<int>{};

        stack<TreeNode*> st;
        st.push(root);
        vector<int> res;

        while (st.size())
        {
            TreeNode *node = st.top();
            st.pop();
            res.push_back(node -> val);
            if (node -> right)
                st.push(node -> right);
            if (node -> left)
                st.push(node -> left);
        }
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    
    root.left = &node2;
    root.right = &node3;
    node3.left = &node4;
    node4.right = &node5;
    
    Solution s;
    for (auto i : s.preorderTraversal(&root))
        std::cout << i << " ";
    std::cout << std::endl; 
    
	return 0;
}