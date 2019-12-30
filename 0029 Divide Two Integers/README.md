## 算法1

**(倍增做减法)*O($(logx)^{2}$)***

基本思路使用移位和加减法替代乘除，因为任何INT除法运算可以表示为 X = y * N, N = 2^0 + 2^1 + 2^2 + 2^3 + ......。 这道题的难点在于 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。 这会造成两个麻烦:

1. 移位有限制，无法使用long等类型
2. 针对INT_MIN，无法直接转换为正数 对策：
3. 提前判断是否移位越界
4. 先提前dividend += abs(divisor)，然后结果加1，然后在转为正数计算即可

```CPP
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)  return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)  return INT_MAX;
        
        long long m = abs((long)dividend), n = abs((long)divisor);
        long long res = 0;
        
        while (m >= n)
        {
            long long t = n, shift = 1;
            while (2 * t <= m)
            {
                t *= 2;
                shift *= 2;
            }
            res += shift;
            m -= t;
        }
        return (dividend > 0) ^ (divisor > 0) ? -res : res;
    }
};
```

```Python
class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        flag = 1 if (dividend<0 and divisor<0) or (dividend>0 and divisor>0)  else -1
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            tmp, i = divisor, 1
            while dividend >= tmp:
                dividend -= tmp
                res += i
                tmp <<= 1
                i   <<= 1
        if flag < 0:
            res = -res
            
        return min(max(-2147483648, res), 2147483647)
```