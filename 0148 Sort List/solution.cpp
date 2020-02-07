#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    // Top to Down  Time complexity: O(nlogn), Space complexity: O(logn)
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)    return head;
        
        //step 1. cut the list to two halves
        ListNode *fast = head->next, *slow = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        //step 2. sort each half
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(fast);
        
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode *dummy = new ListNode(0), *p = dummy;
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
        if(l1)    p->next = l1;
        if(l2)    p->next = l2;
        
        return dummy->next;
    }
};

void printList(ListNode *head)
{
    while(head)
    {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

int main(){
    ListNode *head = new ListNode(4);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(1);
    ListNode *n4 = new ListNode(3);
    head -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;

    printList(head);
    head = Solution().sortList(head);
    printList(head);

    return 0;
}