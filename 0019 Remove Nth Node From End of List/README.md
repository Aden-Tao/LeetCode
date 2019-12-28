## 算法1

**(两次遍历)O(*L*)**

1. 第一次遍历求出链表长度；
2. 第二次遍历删除指定节点；
3. 注意删除头尾的特殊情况;

```CPP
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-99999);
        dummy -> next = head;
        int L = 0;
        ListNode* p = head;
        
        while( p != NULL ){
            L ++;
            p = p -> next;
        }
        
        p = dummy;  //不指向head，防止只有一个元素又要删除这个元素的情况
        for(auto i = 0;i < L - n;i ++)
            p= p -> next; 
        p -> next = p -> next -> next;
        
        return dummy -> next;
    }
};
```

## 算法1

**(一次遍历)O(*L*)**

1. 设置保护节点；
2. 设置两个节点*first*和*second*均指向保护节点；
3. *first*先走*n + 1*个节点；
4. 然后*first*和*second*同时向后移动，直到*first*指针指向空，此时*second*节点下一个节点需要删除；
   
```Python
class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # two pointer , one pass
        dummy = ListNode(-99999)
        dummy.next = head
        first = second = dummy
        
        for i in range(n):
            first = first.next
        
        while first and first.next:
            first = first.next
            second = second.next
        
        second.next = second.next.next
        
        return dummy.next
```