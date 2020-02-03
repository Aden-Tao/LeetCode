## 算法1

**(树的遍历)*O(n)***

这道题目考察了对树和链表的操作。

先定义右链：指一棵子树最右侧的路径。
我们从根节点开始迭代，每次将当前节点的左子树的右链，插入当前节点的右链.

```CPP
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur)
        {
            if (cur->left)
            {
                TreeNode* tmp = cur->left;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};
```