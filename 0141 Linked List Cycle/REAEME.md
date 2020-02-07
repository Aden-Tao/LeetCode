## 算法1

**(链表，指针扫描) *O(n)***

用两个指针从头开始扫描，第一个指针每次走一步，第二个指针每次走两步。如果走到 null，说明不存在环；否则如果两个指针相遇，则说明存在环。

```CPP
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast)
        {
            if (!fast->next)  return false;
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
```

```Python
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = slow = head
        while fast:
            if not fast.next:   return False
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
            
        return False
```