## 算法1

**(模拟) O(n)**

模拟列竖加法 

1. 从低位至高位，逐位相加，如果和大于10，则保留个位，同时向前进位1；
2. 最终若有最高为则前面补1；

**CPP代码**
``` CPP
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode *res = new ListNode(-1);   //添加虚拟头结点，简化边界情况的判断
        ListNode *cur = res;
        int carry = 0;  //表示进位
        while (l1 || l2) 
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1); //如果最高位有进位，则需在最前面补1.
        return res->next;   //返回真正的头结点
    }
};
```

**Python代码**
``` Python
class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        p = head
        quot = 0
        while l1 or l2 or quot != 0:
            if l1:
                quot += l1.val
                l1 = l1.next
            if l2:
                quot += l2.val
                l2 = l2.next
            quot, rem = divmod(quot, 10)
            p.next = ListNode(rem)
            p = p.next

        return head.next
```