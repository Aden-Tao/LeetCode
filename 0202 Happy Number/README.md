## 算法1

**(哈希)*O(1)***

用 unordered_set 来存之前已经算出过的数字。

1. 计算每位数字的平方和
2. 结果为1，则返回True
3. 结果已出现过，说明陷入死循环，返回False
4. 其他情况则重新计算每位数字的平方和，并把结果加入set

```CPP
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (true)
        {
            int t = 0;
            while (n)
            {
                t += (n % 10) * (n % 10);
                n /= 10;
            }

            if (t == 1)
                return true;
            else if (st.find(t) != st.end())
                return false;
            else
                st.insert(t);
            n = t;
        }
    }
};
```

## 算法2

**(快慢指针)*O(1)***

把sum的值看成是一个链表，那么问题转换成链表是否有环。 用快慢指针判断链表中是否有环，slow和fast最后一定会收敛到某个数字。

```Python
class Solution:
    def isHappy(self, n: int) -> bool:
        slow = self.helper(n)
        fast = self.helper(slow)
        
        while slow != fast :
            slow = self.helper(slow)
            fast = self.helper(self.helper(fast))
        
        if slow == 1:
            return True
        else:
            return False

    def helper(self, n):
        r = 0
        while n:
            r += (n % 10) ** 2
            n //= 10
        
        return r
```