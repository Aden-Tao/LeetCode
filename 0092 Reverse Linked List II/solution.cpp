#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        for (int i = 0; i < m - 1; i ++ )
            p = p->next;
        ListNode *a = p, *b = a->next, *c = b->next;
        for (int i = m + 1; i <= n; i ++ )
        {
            ListNode *d = c->next;
            c->next = b;
            b = c;
            c = d;
        }
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};

ListNode *createLinkedList(vector<int>::iterator beg, vector<int>::iterator end)
{
    ListNode *head = beg == end ? NULL : new ListNode(*beg ++);
    for (ListNode *cur = head; beg != end; cur = cur->next)
        cur->next = new ListNode(*beg++);
    return head;
}

void printAndClear(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head -> next) cout << "->";
        ListNode *del = head;
        head = head->next;
        delete del;
    }
    cout << endl;
}

int main(){
    vector<int> vec{1, 2, 3, 4, 5};
    ListNode *head = createLinkedList(vec.begin(), vec.end());
    Solution s;
    ListNode *res = s.reverseBetween(head, 2, 4);
    printAndClear(res);
    return 0;
}