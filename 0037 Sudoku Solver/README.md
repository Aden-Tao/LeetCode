## 算法1

**(深度优先搜索 DFS)**

1. 首先按照上一题Valid Sudoku的方法，预处理出 row、 col、 cell数组;
2. 从 (0,0) 位置开始深度优先搜索， 遇到 . 时，枚举可以填充的数字， 然后判重并加入 row、 col、 cell 数组中；
3. 如果成功到达结尾，则返回 ```true```；


```CPP
class Solution {
public:
    bool row[9][9] = {0}, col[9][9] = {0}, cell[3][3][9] = {0};
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i ++)
            for (int j = 0; j < 9; j ++)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int t = c - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                }
            }
        dfs(board, 0, 0);
    }
    
    bool dfs(vector<vector<char>> &board, int x, int y)
    {
        if (y == 9)  x ++, y = 0;
        if (x == 9)  return true;
        if (board[x][y] != '.')  //当前已经填过
            return dfs(board, x, y + 1);
        
        for (int i = 0; i < 9; i ++)
            if (!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i])
            {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
                if (dfs(board, x, y + 1))  return true;
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
                board[x][y] = '.';
            }
        return false;
    }
};
```