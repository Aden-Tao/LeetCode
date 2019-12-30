#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *p = dummy;
        
        while (p)
        {
            ListNode *first = p -> next;
            if (!first)  break;
            
            ListNode *second = first -> next;
            if (!second) break;
            
            p -> next = second;
            first -> next = second -> next;
            second -> next = first;
            
            p = first;
        }
        return dummy -> next;
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
    ListNode *head = create_linkedlist({1,2,3,4});
    ListNode *ret = s.swapPairs(head);
    printList(ret);
    clear(ret);

    return 0;
}