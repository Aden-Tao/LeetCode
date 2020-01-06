#include <bits/stdc++.h>
using std::vector;

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
                    grid[i][j] += std::min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec = {
        {1,3,1}, {1,5,1}, {4,2,1}
    };
    assert(s.minPathSum(vec) == 7);
    return 0;
}