## 算法1

**(线性合并)O(*n*)**

1. 新建头部节点，设置 *p*指向头部节点；
2. 若 *l1* 节点的 *val* 小于 *l2* 节点的 *val* , 则令 *p* 的 *next* 指针指向 *l1* , 且 *l1* 后移; 否则指向 *l2*, 且*l2*后移；
3. 然后 *p* 后移；
4. 循环直到 *l1* 或 *l2*为空；
5. 将剩余 *l1* 或 *l2* 接到 *p* 指针后边；

```CPP
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(-9999);
        ListNode* p = head;
        // head->next = (l1->val >= l2->val) ? l1 : l2;
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        if(l1)
            p->next = l1;
        if(l2)
            p->next = l2;
        
        return head->next;
    }
};
```