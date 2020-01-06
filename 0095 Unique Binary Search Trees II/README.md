## 算法1

**(DFS)*O($C^{n}_{2n}/(n+1)$)***
递归搜索所有方案:<br>
1. 对于每段连续的序列 ```l,l+1,…rl,l+1,…r```，枚举二叉搜索树根节点的位置；
2. 分别递归求出左右子树的所有方案；
3. 左子树的任意一种方案和右子树的任意一种方案拼在一起，可以得到当前节点的一种方案，所以我们将左右子树的所有方案两两组合，并记录在答案中。

```CPP
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
```

```Python
class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if(n == 0):    return []
        
        return self.dfs(1, n)
    
    def dfs(self, s, e):
        if s > e:
            return [None]
        
        res = []
        for cur_root in range(s, e + 1):
            left = self.dfs(s, cur_root - 1)
            right = self.dfs(cur_root + 1, e)
            
            for l in left:
                for r in right:
                    root = TreeNode(cur_root)
                    root.left = l
                    root.right= r
                    res.append(root)
        return res
```