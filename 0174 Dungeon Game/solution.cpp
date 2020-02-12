#include "bits/stdc++.h"
using namespace std;

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

int main(){
    vector<vector<int>> dungeon{
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << Solution().calculateMinimumHP(dungeon) << endl;

    return 0;
}