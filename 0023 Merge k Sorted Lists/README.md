## 算法1

**(优先队列)*O(Nlogk)*** n是所有链表中元素的总和，k是链表的数目

用优先队列

```CPP
class Solution {
    struct compare{
        bool operator()(const ListNode* l, const ListNode* r){
            return l->val > r->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(auto l: lists)
            if(l)
                q.push(l);
        
        if(q.empty())
            return NULL;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        while(!q.empty()){
            cur->next = q.top();
            cur = cur->next;
            q.pop();
            if(cur->next)
                q.push(cur->next);
        }
        
        return dummy->next;
        
    }
};
```

```Python
from Queue import PriorityQueue

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next
```

## 算法2

**(分而治之，链表两两合并)*O(Nlogk)***

```CPP
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())  return NULL;
        int n = lists.size();
        while(n > 1){
            int k = (n + 1) / 2;
            for(int i=0; i<n/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
    
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
