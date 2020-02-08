#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q)
        {
            if (p)  p = p -> next;
            else    p = headB;
            if (q)  q = q -> next;
            else    q = headA;
        }
        return p;
    }
};

int main(){
    ListNode *headA = new ListNode(4);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(8);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    ListNode *headB = new ListNode(5);
    ListNode *h2 = new ListNode(0);
    ListNode *h3 = new ListNode(1);

    headA -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n5;

    headB -> next = h2;
    h2 -> next = h3;
    h3 -> next = n3;

    cout << Solution().getIntersectionNode(headA, headB) -> val << endl;

    return 0;
}