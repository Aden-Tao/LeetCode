## 算法1

**(线性扫描)*O(n)***

定义两个头节点，分别存储两个部分对应的链表。
然后遍历原链表，对于每个节点，如果小于```x```,则插入第一个链表；否则，插入第二个链表。最后将第二个链表插入第一个链表末尾。

```CPP
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        ListNode *p = l1, *q = l2;

        for (ListNode *t = head; t; t = t->next)
            if (t->val < x)
            {
                p->next = t;
                p = t;
            }
            else
            {
                q->next = t;
                q = t;
            }

        p->next = l2->next;
        q->next = 0;

        return l1->next;
    }
};

```

```Python
class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        nL1 = L1 = ListNode(-1)
        nL2 = L2 = ListNode(-2)
        
        while head != None:
            if head.val < x:
                L1.next = head
                L1 = L1.next
            else:
                L2.next = head
                L2 = L2.next
            head = head.next
        
        L2.next = None
        L1.next = nL2.next
        
        return nL1.next
```