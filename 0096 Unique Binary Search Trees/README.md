## 算法1

**(动态规划)*O($n^{2}$)***

状态表示：f[n]表示 n个节点的二叉搜索树共有多少种。<br>
状态转移：左子树可以有 ```0,1,…n−1``` 个节点，对应的右子树有 ```n−1,n−2,…,0``` 个节点，f[n]是所有这些情况的加和。所以 f[n] = $\sum_{k=0}^{n-1}$f[k] * f[n - 1 - k]

时间复杂度分析：状态总共有 n 个，状态转移的复杂度是 O(n)，所以总时间复杂度是 O($n^{2}$) 。

```CPP
class Solution {
public:
    int numTrees(int n) {
        vector<int> f (n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 0; j < i; j ++)
                f[i] += f[j] * f[i - j - 1];
        }
        
        return f[n];
    }
};
```

