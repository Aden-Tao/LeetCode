## 算法1

**(模拟)*O(n)***

1.  将 m 到 n 之间的指针反转；
2.  将 m 指向 原先 n 指针的下一个节点，将原 m 指针的前驱节点的next指向 n 指针所指节点；

```CPP
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        for (int i = 0; i < m - 1; i ++ )
            p = p->next;
        ListNode *a = p, *b = a->next, *c = b->next;
        for (int i = m + 1; i <= n; i ++ )
        {
            ListNode *d = c->next;
            c->next = b;
            b = c;
            c = d;
        }
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};
```

```Python
class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        p, cnt = dummy, 1
        
        while m>cnt and head:
            cnt += 1 
            p.next, head = head, head.next
            p = p.next
            
        p.next = None
        while head and cnt<=n:
            cnt += 1
            p.next, head, p.next.next = head, head.next, p.next
            
        for _ in range(m, n+1):
            p = p.next
        
        while head:
            p.next, head = head, head.next
            p = p.next
            
        return dummy.next
```