#! python3

from queue import PriorityQueue

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists):
        k = len(lists)
        q = PriorityQueue(maxsize=k)
        dummy = ListNode(None)
        curr = dummy
        for list_idx, node in enumerate(lists):
            if node: q.put((node.val, list_idx, node))
        while q.qsize() > 0:
            poped = q.get()
            curr.next, list_idx = poped[2], poped[1]
            curr = curr.next
            if curr.next: q.put((curr.next.val, list_idx, curr.next))
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
    lists = [
        createLinkedlist([1,4,5]),
        createLinkedlist([1,3,4]),
        createLinkedlist([2,6])
    ]
    res = Solution().mergeKLists(lists)
    printList(res)



