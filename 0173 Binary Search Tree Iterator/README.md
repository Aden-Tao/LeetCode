## 算法1

**(栈)*O(n)***

1. 用栈来模拟BST的中序遍历过程，当前结点进栈，代表它的左子树正在被访问，栈顶结点代表当前访问到的结点；
2. 求后继时，只需要弹出栈顶结点，取出它的值，然后将它的右儿子以及右儿子的左儿子等一系列结点进栈，这一步代表找右子树中的最左子结点，并记录路径上的所有结点；
3. 判断是否还存在后继只需要判断栈是否为空即可，因为栈顶结点是下一次即将被访问到的结点；

```CPP
class BSTIterator {
public:
    
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* p = s.top();
        s.pop();
        int val = p->val;
        p = p->right;
        while (p)
        {
            s.push(p);
            p = p->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};
```