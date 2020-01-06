## 算法1

**(动态规划)*O(mn)***

类似于[62 Unique Paths](../0062&#32;Unique&#32;Paths/README.md) 不同的在网格障碍物处，路径维数是0

```CPP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> f(n, vector<long long> (m, 0));
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
            {
                if (obstacleGrid[i][j])
                    continue;
                if (!i && !j)
                    f[i][j] = 1;
                if (i > 0)  f[i][j] += f[i - 1][j];
                if (j > 0)  f[i][j] += f[i][j - 1];
            }
        }
        return f[n - 1][m - 1];
    }
};
```