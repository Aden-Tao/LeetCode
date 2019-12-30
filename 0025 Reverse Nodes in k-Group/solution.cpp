#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head -> next || k < 2)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *tail = dummy, *tmp = NULL;
        
        while (true)
        {
            for (int i = 0; i < k && tail; i ++)
                tail = tail -> next;
            if (!tail)  break;
            
            ListNode *head = pre -> next;
            while(pre -> next != tail)
            {
                tmp = pre -> next;
                pre -> next = tmp -> next;
                tmp -> next = tail -> next;
                tail -> next = tmp;
            }
            pre = head;
            tail = head;
        }
        return dummy -> next;
    }
};

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main()
{
    Solution s;
    ListNode *head = s.reverseKGroup(create_linkedlist({1,2,3,4,5}), 3);
    for (ListNode *cur=head; cur; cur=cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b  " << std::endl;

    return 0;
}