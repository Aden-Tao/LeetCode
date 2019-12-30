## 算法1

**(模拟)*O(L)***

1. 增加虚拟头结点dummy，并且令pre指针指向dummy;
2. 对于每一轮的修改，令head指针为pre->next，并求出tail指针为下一轮需要交换的最后一个结点；在找tail的过程中，若不足k个结点，则直接终止循环;
3. 在找到head和tail后，每次让prev.next的元素插入到当前tail之后,这样tail不断前移,被挪动的元素头插入tail之后的链表，需要一个临时的tmp指针（参考代码）;
4. 最终修改pre和head指向;
5. 返回dummy->next;

```CPP
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 *----------------------------
 *prev
 *tail   head
 *dummy   1    2    3   4    5
 *----------------------------
 *prev   head      tail
 *dummy   1    2    3   4    5
 *       cur
 *----------------------------
 * 每次让prev.next的元素插入到当前tail之后,这样tail不断前移,被挪动的元素头插入tail之后的链表
 *prev        tail head
 *dummy   2    3    1   4    5
 *       cur
 *----------------------------
 *prev   tail      head
 *dummy   3    2    1   4    5
 *       cur
 *----------------------------
 *                 prev
 *                 tail
 *                 head
 *dummy   3    2    1   4    5
 *----------------------------
 *                 prev  head     tail
 *dummy   3    2    1     4    5  null
 *----------------------------
  */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head -> next || k < 2)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *tail = dummy, *tmp = NULL;
        
        while (true)
        {
            for (int i = 0; i < k && tail; i ++)
                tail = tail -> next;
            if (!tail)  break;
            
            ListNode *head = pre -> next;
            while(pre -> next != tail)
            {
                tmp = pre -> next;
                pre -> next = tmp -> next;
                tmp -> next = tail -> next;
                tail -> next = tmp;
            }
            pre = head;
            tail = head;
        }
        return dummy -> next;
    }
};
```