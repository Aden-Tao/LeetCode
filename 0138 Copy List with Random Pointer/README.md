## 算法1

**(有丝分裂，原地复制) *O(n)***

1. 复制节点，同时将复制节点链接到原节点后面，如A->B->C 变为 A->A'->B->B'->C->C';
2. 设置节点random值;
3. 将复制链表从原链表分离;

```CPP
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node *p = head;
        while (p)
        {
            Node * tmp = new Node(p -> val);
            tmp -> next = p -> next;
            p -> next = tmp;
            p = tmp -> next;
        }
        p = head;
        while (p)
        {
            p -> next -> random = p -> random ? p -> random -> next : NULL;
            p = p -> next -> next;
        }
        p = head;
        Node *clone = p -> next, *tmp;
        while (p)
        {
            tmp = p -> next;
            p -> next = tmp -> next;
            tmp -> next = tmp -> next ? tmp -> next -> next : NULL;
            p = p -> next;
        }
        return clone;
    }
};
```