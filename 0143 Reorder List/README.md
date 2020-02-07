## 算法1


**(链表，模拟) *O(n)***

重排链表分解为以下三个步骤：

1. 首先重新排列后，链表的中心节点会变为最后一个节点。所以需要先找到链表的中心节点；
2. 可以按照中心节点将原始链表划分为左右两个链表。
    * 按照中心节点将原始链表划分为左右两个链表，左链表：1->2->3 右链表：4->5；
    * 将右链表反转，就正好是重排链表交换的顺序，右链表反转：5->4。反转链表；
3. 合并两个链表，将右链表插入到左链表，即可重新排列：1->5->2->4->3；


```CPP
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
```