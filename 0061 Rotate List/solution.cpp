#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head -> next)  return head;
        int len = 1;
        ListNode *f = head, *s = head;
        while (f -> next)
        {
            len ++;
            f = f -> next;
        }
        k = k % len;
        f -> next = head;
        for (int i = len - k - 1; i > 0; i --)
            s = s -> next;
        ListNode *res = s -> next;
        s -> next = NULL;
        return res;
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

int main(){
    Solution s;
    ListNode *head = s.rotateRight(create_linkedlist({1,2,3,4,5}), 6);
    for (ListNode *cur=head; cur; cur=cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b  " << std::endl;
    return 0;
}