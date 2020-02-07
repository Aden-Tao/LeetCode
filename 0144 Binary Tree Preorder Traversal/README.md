## 算法1 

**(树的遍历) *O(n)***

从根节点开始，每次迭代弹出当前栈顶元素，并将其孩子节点压入栈中，先压右孩子再压左孩子。

```CPP
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
```