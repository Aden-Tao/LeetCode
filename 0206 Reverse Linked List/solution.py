#! python3
from __future__ import print_function

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

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
        
def createListNode(nums):
    if len(nums) == 0:
        return None
    head = ListNode(nums[0])
    p = head
    for i in nums[1:]:
        p.next = ListNode(i)
        p = p.next
    return head

if __name__ == "__main__":
    head = createListNode([1,2,3,4,5])
    head = Solution().reverseList(head)
    while head:
        if head.next:
            print (head.val,end='->')
        else:
            print(head.val)
        head = head.next
        