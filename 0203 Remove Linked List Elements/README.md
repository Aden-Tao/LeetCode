## 算法1

**(模拟链表)*O(1)***

定义一个虚拟头结点指向原链表的头结点。

然后从虚拟头结点开始遍历，当下一个节点的值等于 val 时，我们将当前节点的 next 指针指向下一个节点的 next 指针，从而将下一个节点删除。

```CPP
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        for (ListNode *p = dummy; p;)
        {
            if (p->next && p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return dummy->next;
    }
};
```