#! python3

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

if __name__ == "__main__":
    print(Solution().divide(10, 3))