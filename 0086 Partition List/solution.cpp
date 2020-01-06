#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode(0);
        ListNode *l2 = new ListNode(0);
        ListNode *p = l1, *q = l2;

        for (ListNode *t = head; t; t = t->next)
            if (t->val < x)
            {
                p->next = t;
                p = t;
            }
            else
            {
                q->next = t;
                q = t;
            }

        p->next = l2->next;
        q->next = 0;

        return l1->next;
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
    vector<int> vec{1, 4, 3, 2, 5, 2};
    ListNode *head = createLinkedList(vec.begin(), vec.end());
    Solution s;
    ListNode *res = s.partition(head, 3);
    printAndClear(res);
    return 0;
}