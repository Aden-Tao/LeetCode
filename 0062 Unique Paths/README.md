## 算法1

**(动态规划)*O(nm)***

```dp[i][j]``` 表示起点到点 ```(i,j)```的路径总数，递推公式为 : ```dp[i][j] = dp[i][j - 1] + dp[i - 1][j]```，再考虑边界情况，当 ```i == 1 || j == 1 ```时，```dp[i][j] = 1```。

```CPP
class Solution {
public:
    int uniquePaths(int m, int n) {
        //DP 递推
        //初始化 在第一行和第一列都只有一种可能
        vector<vector<int>> res(m, vector<int>(n, 1));
        
        for(int i=1; i<m; i++){
            for(int j=1;j<n; j++){
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};
```