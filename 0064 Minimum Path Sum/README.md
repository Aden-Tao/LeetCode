## 算法1

**(动态规划)*O(mn)***

用```dp[i][j]```记录到达网格```grid[i][j]```位置经过的最小的路径和，转移方程为: ```dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])```

```CPP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (auto i=0; i<m; i++){
            for(auto j=0; j<n; j++){
                if (i==0 && j==0)
                    continue;
                else if (i==0 && j!=0) 
                    grid[i][j] += grid[i][j-1];
                else if (i!=0 && j==0) 
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};
```