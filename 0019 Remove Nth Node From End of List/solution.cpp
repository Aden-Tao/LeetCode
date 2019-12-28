#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-99999);
        dummy -> next = head;
        int L = 0;
        ListNode* p = head;
        
        while( p != NULL ){
            L ++;
            p = p -> next;
        }
        
        p = dummy;  //不指向head，防止只有一个元素又要删除这个元素的情况
        for(auto i = 0;i < L - n;i ++)
            p= p -> next; 
        p -> next = p -> next -> next;
        
        return dummy -> next;
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
    ListNode *res = s.removeNthFromEnd(head, 2);
    printAndClear(res);

    return 0;
}