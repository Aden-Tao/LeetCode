#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast)
        {
            if (!fast->next)  return false;
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main(){
    ListNode *head = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);

    head -> next = n2;
    n2 -> next = n3;
    n3 -> next = n4;
    n4 -> next = n2;

    cout << Solution().hasCycle(head) << endl; 

    return 0;
}