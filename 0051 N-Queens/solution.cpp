#include <bits/stdc++.h>
using std::string; using std::vector;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // method1
        res.clear();
        board = vector<string>(n, string(n, '.'));
        cols = vector<int>(n, 0);
        diag1 = vector<int>(2*n-1, 0);
        diag2 = vector<int>(2*n-1, 0);
        nqueens(n, 0);
        
        return res; 
    }
    
private:
    vector<string> board;
    vector<int> cols, diag1, diag2;
    vector<vector<string>> res;
    
    bool available(int x, int y, int n){
        return !cols[x] && !diag1[x + y] && !diag2[x - y + n - 1];
    }
    
    void updateBoard(int x, int y, int n, bool is_put){
        cols[x] = is_put;
        diag1[x + y] = is_put;
        diag2[x - y + n - 1] = is_put;
        board[y][x] = is_put ? 'Q' : '.';
    }
    
    //try to put the queen on y-th row
    void nqueens(const int n, const int y){
        if(y == n){
            //found one solution, add to the ans set
            res.push_back(board);
            return;
        }    
        
        //Try every column
        for(int x = 0; x < n; ++ x){
            if(!available(x, y, n))  continue;
            updateBoard(x, y, n, true);
            nqueens(n, y + 1);
            updateBoard(x, y, n, false);
        }
    }
};

int main(){
    Solution s;
    for (const auto &v : s.solveNQueens(4)) {
        for (const auto &s : v)
            std::cout << s << std::endl;
        std::cout << std::endl;
    }
    return 0;
}