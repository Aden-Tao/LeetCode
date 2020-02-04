## 算法1

**(BFS，树的遍历) *O(n)***

从根节点开始宽度优先遍历，每次遍历一层，遍历时按从左到右的顺序，对于每个节点，先让左儿子指向右儿子，然后让右儿子指向下一个节点的左儿子。最后让这一层最右侧的节点指向NULL。
遍历到叶节点所在的层为止。

模拟一下操作流程：

第一步，遍历根节点，我们让根节点的左儿子指向右儿子，即让2指向3；<br>
第二步，从左到右遍历第二层，先遍历2，让2的左儿子指向右儿子，即让4指向5，再让2的右儿子指向下一个节点的左儿子，即5指向6；然后遍历3，依次类推；<br>
第三步，我们发现第三层已经是叶节点，算法终止；

```CPP
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return NULL;
        Node* cur = root;
        while(cur -> left)
        {
            for (Node* p = cur; p ; p = p -> next)
            {
                p -> left -> next = p -> right;
                if (p -> next)
                    p -> right -> next = p -> next -> left;
            }
            cur = cur -> left;
        }
        return root;
    }
};
```