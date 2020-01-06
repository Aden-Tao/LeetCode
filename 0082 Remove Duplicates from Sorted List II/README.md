## 算法1

**(线性扫描)*O(n)***

从前往后扫描整个链表，每次扫描元素相同的一段，如果这段中的元素个数多于1个，则将整段元素直接删除。

```CPP
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)    return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;

        while(head && head->next)
        {
            if(head->val == head->next->val){
                while(head && head->next && head->val == head->next->val)
                    head = head->next;
                head = head->next;
                p->next = head;
            }
            else{
                head = head->next;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
```

```Python
```