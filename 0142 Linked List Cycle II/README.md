## 算法1

**(链表，快慢指针扫描) *O(n)***

使用快慢指针，快指针每次走两格，慢指针每次走一格，当两个指针第一次相遇的时候，将慢指针返回起始点，然后快慢指针每次走一格，再次相遇就是环的入口节点。<br>

![1](./img/6314_11dfed2eaa-QQ20190720-004120@2x.png)

证明：假设A是链表起点，B是链表环的入口，C是二者第一次相遇的地方。AB，BC，CB的距离分别为x,y,z，那么环的长度就是 y+z 二者第一次相遇时，可以知道二者分别走过的距离是：

slow:x+y+k1(y+z)<br>
quick:x+y+k2(y+z)<br>
因为快节点走过的距离是慢节点的两倍：2(x+y+k1(y+z))=x+y+k2(y+z)
可以得到x+y=(k2−k1)(y+z)
进一步得到x=(k2−k1−1)(y+z)+z
也就是说AB之间的距离是整数倍个环长度加上CB的长度。那么如果两个节点分别在A，C两点开始走，一个节点从A走到B dist=x ，另一个节点必然也会同时到达B，dist=(k2−k1−1)(y+z)+z。

```CPP
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
```