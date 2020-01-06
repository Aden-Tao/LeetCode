## 算法1

**(模拟 链表)*O(n)***

1. k 可能很大，令 ```k %= n```, n 为链表长度；
2. 创建两个指针 ```first, second```，分别指向虚拟头节点，先让 ```first```向后移动 k 个位置， 然后 ```first```和```second```同时向后移动，直到```first```走到链表最后一个位置；
3. 此时 ```first```指向链表末尾, ```second```指向分界点，然后把链表从分界点处断开，然后把后半段接在前半段即可;

```CPP
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
```