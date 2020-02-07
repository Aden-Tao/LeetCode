## 算法1

**(树的遍历) *O(n)***

取巧的方法。该写法的访问顺序并不是后序遍历，而是利用先序遍历“根左右”的遍历顺序，将先序遍历顺序更改为“根右左”，反转结果List，得到结果顺序为“左右根”。

```CPP
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
```