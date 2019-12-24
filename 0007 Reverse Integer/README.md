## 算法1

**(循环)O(1)**

依次从右往左计算出每位数字，然后逆序累加在一个整数中。需要注意两点：

1. int型可能会溢出，需要用long long 类型记录中间结果；
2. 在CPP中，负数取模运算还是负数

```CPP
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < INT_MIN || res > INT_MAX) return 0;
        return res;
    }
};
``` 

```Python
class Solution(object):
  
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # 定义用来标记给定整数x的正负情况，若x>=0， 则flag=1；反之，则flag=-1
        flag = 1 if x >= 0 else -1
        abs_x = abs(x)
        # 将abs(x)变成字符串
        x_str = str(abs_x)
        # 将字符串x_str反转
        reverse_x_str = x_str[::-1]
        # 最后恢复成整数
        reverse_x_int = int(reverse_x_str) * flag
        if -2 ** 31 <= reverse_x_int <= 2**31 - 1:
            return reverse_x_int
        else:
            return 0
```