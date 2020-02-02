## 算法1

**(BFS)*O(n)***

与 [Binary Tree Level Order Traversal](../0102%20Binary%20Tree%20Level%20Order%20Traversal/README.md) 基本一样，只需将结果翻转一下即可。

```CPP
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
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
        reverse(res.begin(), res.end());
        return res;
    }
};
```