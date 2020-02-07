## 算法1

**(插入排序) *O($n^2$)***

建立虚拟头结点，指向原链表头部。
然后扫描原链表，对于每个节点 v，从前往后扫描结果链表，找到第一个比 v 大的节点 u，将 v 插入到 u之前。

```CPP
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        while (head)
        {
            ListNode *t = head -> next;
            ListNode *p = dummy;
            while (p -> next && p -> next -> val < head -> val)
                p = p -> next;
            head -> next = p -> next;
            p -> next = head;
            head = t;
        }
        return dummy -> next;
    }
};
```