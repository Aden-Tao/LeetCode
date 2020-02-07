## 算法1

**(归并排序) 时间复杂度 O(nlogn) 空间复杂度 O(logn)**

1. 利用快慢指针将输入链表平分成两个链表
2. 递归调用sortList()对这两个链表分别排序
3. 调用mergeTwoLists()来合并两个有序链表

```CPP
class Solution {
public:
    // Top to Down  Time complexity: O(nlogn), Space complexity: O(logn)
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)    return head;
        
        //step 1. cut the list to two halves
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = slow -> next;
        slow -> next = NULL;
        
        //step 2. sort each half
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(fast);
        
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(0), *p = dummy;
        while(l1 && l2){
            if(l1 -> val <= l2 -> val)
            {
                p -> next = l1;
                l1 = l1 -> next;
                p = p -> next;
            }
            else
            {
                p -> next = l2;
                l2 = l2 -> next;
                p = p -> next;
            }
        }
        if(l1)    p -> next = l1;
        if(l2)    p -> next = l2;
        
        return dummy -> next;
    }
};
```