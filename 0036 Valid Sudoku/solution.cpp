#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, block[9][9] = {0};
        
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[i].size(); j ++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    
                    if(row[i][num] || col[j][num] || block[k][num])
                        return false;
                    
                    row[i][num] = col[j][num] = block[k][num] = 1;
                }
            }
        }
        return true;
    }
};

int main()
{
    std::vector<std::vector<char>> board{
        {'.','1','.','5','2','.','.','.','.'},
        {'.','.','.','.','.','6','4','3','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','9','.','.'},
        {'.','.','.','.','.','.','.','5','.'},
        {'.','.','.','5','.','.','.','.','.'},
        {'9','.','.','.','.','3','.','.','.'},
        {'.','.','6','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
    };
    
    Solution s;
    std::cout << s.isValidSudoku(board) << std::endl;
}