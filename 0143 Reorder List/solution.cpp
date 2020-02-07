#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head -> next || !head -> next -> next)
            return;
        ListNode *fast = head, *slow = head;
        //找到中间节点（如果有两个中间节点,slow是靠后的那个）
        while (fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        //反转slow后面的所有节点
        ListNode *pre = slow;
        ListNode *cur = slow -> next;
        slow -> next = NULL;
        while (cur)
        {
            ListNode *t = cur -> next;
            cur -> next = pre;
            pre = cur;
            if (t == NULL)  break;
            cur = t;
        }
        //此时cur是最后一个节点。跳出循环有两种情况：
        //总共有偶数个节点，最后两个节点就不用反转了；head->next != cur
        //总共有奇数个节点，最后一个节点不用反转。head!= cur
        while(head -> next != cur && head != cur)
        {
            ListNode* temp = cur -> next;
            cur -> next = head -> next;
            head -> next = cur;
            cur = temp;
            head = head -> next -> next;
        }
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

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);

    head -> next = l2;
    l2 -> next = l3;
    l3 -> next = l4;

    printList(head);
    Solution().reorderList(head);
    printList(head);
    return 0;
}