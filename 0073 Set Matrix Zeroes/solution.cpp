#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(matrix[i][j] == 0){
                    for(int ii = 0; ii < m; ii ++)
                        if(matrix[ii][j] != 0)
                            matrix[ii][j] = INT_MAX - 1;
                    
                    for(int jj = 0; jj < n; jj ++)
                        if(matrix[i][jj] != 0)
                            matrix[i][jj] = INT_MAX - 1;
                }
            }
        }
        
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j] == INT_MAX-1)
                    matrix[i][j] = 0;
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec = {
        {1,1,1}, {1,0,1}, {1,1,1}
    };
    s.setZeroes(vec);
    for (auto v : vec)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}