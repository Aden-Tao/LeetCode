#! python3

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

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

def createLinkedlist(lst):
    l = len(lst)
    if not l:
        return None

    head = ListNode(lst[0])
    cur = head
    for i in range(1, l):
        cur.next = ListNode(lst[i])
        i += 1
        cur = cur.next
    return head

def printList(head):
    while head:
        print(head.val, end='->')
        head = head.next
    print("\b\b  ")

if __name__ == "__main__":
    head = createLinkedlist([1,2,3,4])
    res = Solution().swapPairs(head)
    printList(res)

