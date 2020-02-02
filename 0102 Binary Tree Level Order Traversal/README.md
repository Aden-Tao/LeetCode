## 算法1

**(BFS)*O(n)***

宽搜，按层遍历，即：

1. 将根节点插入队列中；
2. 创建一个新队列，用来按顺序保存下一层所有子节点；
3. 对于当前队列中的所有节点，按顺序一次将儿子节点加入新队列，并将当前节点的值记录在答案中；
4. 重复2-3步，直到队列为空；

```CPP
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
```