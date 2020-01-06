#! python3

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

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
    head = createLinkedList([1,2,3,4,5])
    res = Solution().reverseBetween(head, 2, 4)
    printAndClear(res)