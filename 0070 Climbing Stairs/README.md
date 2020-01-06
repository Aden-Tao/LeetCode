## 算法1

**(递推)*O(n)***

定义数组 ```f[i]``` 表示上 ```i```级台阶的方案书， 递推公式： ```f[i] = f[i - 1]+ f[i - 2]```
  

```CPP
class Solution {
public:
    int climbStairs(int n) {
        vector<int>f(n + 1);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i ++ )
            f[i] = f[i - 1] + f[i - 2];
        return f[n];
    }
};
```