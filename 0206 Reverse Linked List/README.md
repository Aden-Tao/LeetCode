## 算法1

**(链表，迭代)*O(n)***

建立一个 dummy 节点， 每次往后遍历并将遍历到的节点插入到 dummy 节点之后。

```Python
class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)

        while head:
            dummy.next, head, dummy.next.next = head, head.next, dummy.next
        return dummy.next
```

## 算法2

**(链表，递归)*O(n)***

假设列表的其余部分已经被反转:

假设列表位：<br>
    ```n(1) -> n(2) -> ... -> n(k-1) -> n(k) ->n (k+1) ->... -> n(m)```<br>
若从节点 n(k+1) 到 n(m)已经反转，而我们正处于 n(k):<br>
我们希望 n(k+1)的 next 指向 n(k), 所以 n(k).next.next = n(k)<br>
还需要保证 n(1).next 指向 null.

```CPP
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
```