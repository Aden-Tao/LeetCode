#include <bits/stdc++.h>
using std::vector;

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

int main(){
    Solution s;
    vector<vector<int>> vec = {
        {0,0,0}, {0,1,0},{0,0,0}
    };
    assert(s.uniquePathsWithObstacles(vec) == 2);
    return 0;
}