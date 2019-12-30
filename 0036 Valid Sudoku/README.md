## 算法1

**(数组判重)*O(n)***

分别用一个数组来记录每行、每列和每个九宫格内数字情况

```CPP
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
```