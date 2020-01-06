## 算法1

**(线性扫描)*O(n)***

从前往后扫描整个链表，如果一个节点和其后继节点相同，则直接删除后继节点，否则指针移动到后继节点。

```CPP
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* p = head;
        while (p->next)
        {
            if (p->val == p->next->val) 
                p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};
```

```Python
```