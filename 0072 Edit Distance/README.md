## 算法1

**()*O()***

状态表示：f[i,j]表示将 w1 的前 i个字符变成 w2 的前 j个字符，最少需要进行多少次操作。
状态转移，一共有四种情况：
1. 将w1[i]删除或在w2[j] 后面添加w1[i]  f[i - 1, j] + 1
2. 将w2[j]删除或在w1[i] 后面添加w2[j]  f[i, j - 1] + 1
3. w1[i] == w2[j],  f[i-1][j-1]
4. w1[i] != w2[i],  f[i-1][j-1] + 1


```CPP
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n + 1, vector<int> (m + 1));

        f[0][0] = 0;
        for (int i = 1; i <= n; i ++)  f[i][0] = i;
        for (int j = 1; j <= m; j ++)  f[0][j] = j;
        
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
            {
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
            }
        return f[n][m];
    }
};
```
