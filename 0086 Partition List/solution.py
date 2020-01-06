#! python3

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

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

def createLinkedList(nums):
    if not nums or len(nums) == 0:
        return None
    head = p= ListNode(nums[0])
    for n in nums[1:]:
        p.next = ListNode(n)
        p = p.next
    return head

def printAndClear(head):
    while head:
        print(head.val, end='')
        if head.next:
            print("->", end='')
        d, head = head, head.next
        del d




if __name__ == "__main__":
    head = createLinkedList([1,4,3,2,5,2])
    res = Solution().partition(head, 3)
    printAndClear(res)