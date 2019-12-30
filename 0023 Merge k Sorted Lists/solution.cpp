#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

void clear(ListNode *head)
{
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

void printList(ListNode *head) {
    for (ListNode *cur = head; cur; cur = cur->next)
        cout << cur->val << "->";
    cout << "\b\b  " << endl;
}

int main()
{
    Solution s;
    vector<ListNode *> vec{
        create_linkedlist({1,4,5}),
        create_linkedlist({1,3,4}),
        create_linkedlist({2,6})
    };
    ListNode *ret = s.mergeKLists(vec);
    printList(ret);
    clear(ret);

    return 0;
}
