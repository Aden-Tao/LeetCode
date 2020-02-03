## 算法1

**(递归)*O($n^2$)***

跟[Convert Sorted Array to Binary Search Tree](../0108%20Convert%20Sorted%20Array%20to%20Binary%20Search%20Tree/README.md)类似，不同之处在于链表找中点时需要遍历,用快慢指针，所以总的复杂的为 *O($n^2$)*

递归建立整棵二叉树。
每次以中点为根，以左半部分为左子树，右半部分为右子树。先分别递归建立左子树和右子树，然后令根节点的指针分别指向两棵子树。

```CPP
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (!head)  return NULL;
        if (!head->next)  return new TreeNode(head->val);
        
        ListNode *fast = head, *slow = head, *pre;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;  //break
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    } 
};
```