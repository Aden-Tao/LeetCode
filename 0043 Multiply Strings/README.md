## 算法1

**(高精度乘法，模拟)*O(nm)***

1. 模拟竖式乘法；
2. 乘积的最大长度为两个乘数的长度之和；

```CPP
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> a(n), b(m), c(n + m);
        
        for (int i = 0; i < n; i ++)
            a[n - 1 - i] = num1[i] - '0';
        for (int i = 0; i < m; i ++)
            b[m - 1 - i] = num2[i] - '0';
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
            {
                c[i + j] += a[i] * b[j];
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
        
        int l = c.size() - 1;
        while (l > 0 && c[l] == 0)
            l--;
        
        string res = "";
        for (int i = l; i >= 0; i --)
            res += c[i] + '0';
        return res;
    }
};
```