#! python3

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

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

if __name__ == "__main__":
    head, n2, n3, n4 = ListNode(3), ListNode(2), ListNode(0), ListNode(-4)
    head.next, n2.next, n3.next, n4.next = n2, n3, n4, n2
    print(Solution().hasCycle(head))