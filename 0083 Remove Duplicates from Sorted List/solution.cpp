#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* p = head;
        while (p->next)
        {
            if (p->val == p->next->val) 
                p->next = p->next->next;
            else p = p->next;
        }
        return head;
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
    vector<int> vec{1, 1, 2, 3, 3};
    ListNode *head = createLinkedList(vec.begin(), vec.end());
    Solution s;
    ListNode *res = s.deleteDuplicates(head);
    printAndClear(res);
    return 0;
}