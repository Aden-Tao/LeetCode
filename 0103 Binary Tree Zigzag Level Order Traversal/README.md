## 算法1

**(BFS)*O(n)***

跟102题类似，增加一个标识位，若为奇数行则反转。

```CPP
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
```