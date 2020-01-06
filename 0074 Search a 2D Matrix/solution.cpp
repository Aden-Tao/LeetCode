#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())  return false;
        
        int n = matrix.size(), m = matrix[0].size(); 
        int l = 0, r = m * n - 1;
        while (l < r)
        {
            int mid = l + r  >> 1;
            if (matrix[mid / m][mid % m] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        
        return matrix[r / m][r % m] == target? true: false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec = {
        {1,   3,  5,  7}, {10, 11, 16, 20}, {23, 30, 34, 50}
    };
    assert(s.searchMatrix(vec, 13) == false);
    assert(s.searchMatrix(vec, 10) == true);

    return 0;
}