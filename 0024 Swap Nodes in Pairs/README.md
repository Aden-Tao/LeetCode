## 算法1

**(模拟)*O(n)***

1. 添加虚拟头节点；
2. 定义 cur 指针初始指向 dummy ;
3. 定义 first 为 cur->next， second 为 first->next; 若 first 或 second 为空，则终止循环；
4. 调换 cur first second 节点的 next 指针;
5. 将 cur 指向修改后的 first；

```CPP
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *p = dummy;
        
        while (p)
        {
            ListNode *first = p -> next;
            if (!first)  break;
            
            ListNode *second = first -> next;
            if (!second) break;
            
            p -> next = second;
            first -> next = second -> next;
            second -> next = first;
            
            p = first;
        }
        return dummy -> next;
    }
};
```

```Python
class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = p1 = ListNode(0)
        dummy.next = head
        
        try:
            while True:
                p0, p1, p2 = p1, p1.next, p1.next.next
                p0.next, p1.next, p2.next = p2, p2.next, p1
        except:
            return dummy.next
```