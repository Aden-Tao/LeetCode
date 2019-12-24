## 算法1

**模拟O(n)**

思路：<br>
1. 过滤掉空格；
2. 判断正负号；
3. 提取数值，要注意处理溢出；

```CPP
class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int k = 0;
        while(k < str.size() && (str[k] == ' ' || str[k] == '\t')) k ++ ;
        int minus = 1;
        if (k >= str.size()) return 0;
        if (str[k] == '-') minus = -1, k ++;
        if (str[k] == '+')
            if (minus == -1) return 0;
            else k ++ ;
        while(str[k] >= '0' && str[k] <= '9')
        {
            res = res * 10 + str[k] - '0';
            k ++ ;
            if (res > INT_MAX) break;
        }
        res *= minus;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return res;
    }
};
```
