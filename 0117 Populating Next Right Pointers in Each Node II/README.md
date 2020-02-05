## 算法1

**(BFS，树的遍历) *O(n)***

跟[Populating Next Right Pointers in Each Node](../0116%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/README.md)类似，不同点在于它不是一棵完美二叉树。

从根节点开始宽度优先遍历，每次遍历一层，从左到右依次遍历每个节点。
遍历时维护下一层节点的链表。对于每个节点，依次判断它的左儿子和右儿子是否在存在，如果存在，则插入下一层链表的末尾。

模拟一下操作流程：

第一步，遍历根节点，依次将它的左右儿子插入下一层链表，得到 2->3；<br>
第二步，从左到右遍历第二层，即遍历 2->3，依次将它们的子节点插入下一层链表，得到 4->5->7；<br>
第三步，遍历到叶节点层，算法结束；<br>

```CPP
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return NULL;
        Node* cur = root;
        while (cur)
        {
            Node* dummy = new Node(0);
            Node* p = dummy;
            while (cur)
            {
                if (cur -> left)
                {
                    p -> next = cur -> left;
                    p = p -> next;
                }
                if (cur -> right)
                {
                    p -> next = cur -> right;
                    p = p -> next;
                }
                cur = cur -> next;
            }
            p -> next = NULL;
            cur = dummy -> next;
        }
        return root;
    }
};
```