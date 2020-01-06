#include <bits/stdc++.h>
using std::vector;

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

int main(){
    Solution s;
    assert(s.uniquePaths(3,2) == 3);
    assert(s.uniquePaths(7,3) == 28);

    return 0;
}