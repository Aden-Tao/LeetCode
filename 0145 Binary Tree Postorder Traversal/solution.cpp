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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)  return res;
        stack<TreeNode*> st;
        for (st.push(root); st.size();)
        {
            root = st.top();
            st.pop();
            if (root -> left)  st.push(root -> left);
            if (root -> right) st.push(root -> right);
            res.push_back(root -> val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/// Test Unit
/* 
 *          1
 *         / \
 *        2   3
 *           /
 *          4
 *           \
 *            5
 */

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
    for (auto i : s.postorderTraversal(&root))
        std::cout << i << " ";
    std::cout << std::endl; 
    
	return 0;
}