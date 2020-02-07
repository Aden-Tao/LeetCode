#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast)
        {
            if (!fast -> next)  return NULL;
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main()
{
    ListNode node1(3);
    ListNode node2(2);
    ListNode node3(0);
    ListNode node4(-4);
    ListNode node5(5);
    ListNode node6(6);
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    
    Solution s;
    std::cout << s.detectCycle(&node1)->val << std::endl;
    
    return 0;
}
