#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        if(matrix.empty()) return res;
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;

        while(u <= d && l <= r){
            for(int i = l; i <= r; i ++){ //to right
                res.push_back(matrix[u][i]);
            }
            u ++;
            
            for(int i = u; i <= d; i ++){ //to down
                res.push_back(matrix[i][r]);
            }
            r --;
            
            for(int i = r; i >= l && u <= d; i --){ // to left
                res.push_back(matrix[d][i]);
            }
            d --;
            
            for(int i = d; i >= u && l <= r; i --){ //to upper
                res.push_back(matrix[i][l]);
            }
            l ++;
        }
        
        return res;
    }
};

int main(){
    Solution s;
    std::vector<std::vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    std::vector<int> res{1,2,3,6,9,8,7,4,5};
    assert(s.spiralOrder(matrix) == res);
    return 0;
}