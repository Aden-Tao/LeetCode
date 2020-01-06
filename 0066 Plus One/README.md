## 算法1

**(模拟)*O(n)***

从低位到高位，依次计算每一位数字，过程中需要记录进位。注意特殊情况就是数字全是9。

```CPP
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i --)
        {
            if (digits[i] < 9)
            {
                digits[i] ++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> res(digits.size() + 1);
        res[0] = 1;
        return res;
    }
};
```

