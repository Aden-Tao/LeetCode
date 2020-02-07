#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        while (head)
        {
            ListNode *t = head -> next;
            ListNode *p = dummy;
            while (p -> next && p -> next -> val < head -> val)
                p = p -> next;
            head -> next = p -> next;
            p -> next = head;
            head = t;
        }
        return dummy -> next;
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
    head = Solution().insertionSortList(head);
    printList(head);

    return 0;
}