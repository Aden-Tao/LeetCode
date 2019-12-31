#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)  return ;
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < i; j ++)
                swap(matrix[i][j], matrix[j][i]);
        
        for (int i = 0; i < n; i ++)
            for (int j = 0, k = n - 1; j < k; j ++, k --)
                swap(matrix[i][j], matrix[i][k]);
        return ;
    }
};

int main(){
    vector<vector<int>> vec{{1,2,3},{4,5,6},{7,8,9}};
    Solution().rotate(vec);
    for (auto v : vec)
    {
        for (auto n : v)
            cout << n <<" ";
        cout << endl;
    }
    return 0;
}