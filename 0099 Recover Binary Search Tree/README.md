## 算法1

**(中序遍历)*O(n)***

中序遍历的结果就是二叉树搜索树所表示的有序数列。有序数列从小到大排序，但有两个数被交换了位置。共有两种情况：

1. 交换的是相邻两个数，例如 1 3 2 4 5 6，则第一个逆序对，就是被交换的两个数，这里是3和2；
2. 交换的是不相邻的数，例如 1 5 3 4 2 6，则第一个逆序对的第一个数，和第二个逆序对的第二个数，就是被交换的两个数，这里是5和2；
找到被交换的数后，我们将它们换回来即可

空间复杂度最坏可达 O(n)

```CPP
class Solution {
public:
    TreeNode *pre, *first, *second; // 前一个访问节点，交换的第一个节点，交换的第二个节点
    
    void recoverTree(TreeNode* root) {
        if(root == NULL)  return;
        
        pre = NULL;
        first = NULL;
        second = NULL;
        
        dfs(root);
        //交换两个节点的值
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
    
    void dfs(TreeNode *root){
        if(root == NULL)
            return;
        
        dfs(root->left);
        
        //访问root节点
        if(pre != NULL && pre->val > root->val){
            if(first == NULL){
                first = pre;
                second = root; // case1: 如果两个元素相邻
            }
            else{
                //case2: 遇到第二个被调换的元素
                second = root;
            }
        }
        pre = root;
        
        dfs(root->right);
    }
};
```

## 算法2

******

从根节点开始遍历，直至当前节点为空为止：

1. 如果当前节点没有左儿子，则打印当前节点的值，然后进入右子树；
2. 如果当前节点有左儿子，则找当前节点的前驱。
   - 如果前驱节点的右儿子为空，说明左子树没遍历过，则进入左子树遍历，并将前驱节点的右儿子置成当前节点，方便回溯；
   - 如果前驱节点的右儿子为当前节点，说明左子树已被遍历过，则将前驱节点的右儿子恢复为空，然后打印当前节点的值，然后进入右子树继续遍历；

复杂度分析：Morris-traversal算法的时间复杂度是 O(n)，额外空间复杂度是 O(1)。
```CPP
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second, *prep = NULL;
        while (root)
        {
            if (!root->left)
            {
                if (prep && prep->val > root->val)
                {
                    if (!first) first = prep, second = root;
                    else second = root;
                }
                prep = root;
                root = root->right;
            }
            else
            {
                TreeNode *p = root->left;
                while (p->right && p->right != root) p = p->right;
                if (!p->right)
                {
                    p->right = root;
                    root = root->left;
                }
                else
                {
                    p->right = NULL;
                    if (prep && prep->val > root->val)
                    {
                        if (!first) first = prep, second = root;
                        else second = root;
                    }
                    prep = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};
```