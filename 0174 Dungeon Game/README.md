## 算法1

**()*O()***

1. 不能直接从正向DP的原因是不确定起始点的值，但我们可以发现，到终点之后健康值为1一定是最优的；
2. 可以考虑从终点到起点进行动态规划；
3. 状态表示为```f[i][j]```表示从 (i, j) 成功到达终点，(i, j)处需要具备的最少健康值;
4. 转移方程为```f[i][j] = min(f[i + 1][j] , f[i][j + 1]) - dungeon[i][j]```；如果```f[i][j] <= 0```，表示道路上的补给实在太多了，但此时健康值不能小于0，所以需要更新```f[i][j] = 1```;
初始值```f[n - 1][m - 1]```为```max(-dungeon[n - 1][m - 1], 0) + 1```;

```CPP
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<long long>> f(n, vector<long long>(m, 1000000000000ll));
        f[n - 1][m - 1] = max(-dungeon[n - 1][m - 1], 0) + 1;
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                if (i < n - 1)
                    f[i][j] = min(f[i][j], f[i + 1][j] - dungeon[i][j]);
                if (j < m - 1)
                    f[i][j] = min(f[i][j], f[i][j + 1] - dungeon[i][j]);
                f[i][j] = f[i][j] <= 0 ? 1 : f[i][j];
            }
        return f[0][0];
    }
};
```