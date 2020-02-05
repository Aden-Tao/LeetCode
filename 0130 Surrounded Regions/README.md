## 算法1

**(Flood Fill, 深度优先遍历) *O($n^2$)***

先统计出哪些区域不会被攻占，然后将其它区域都变成'X'即可。

具体做法如下：

1. 枚举所有边界上的'O'，从该位置做Flood Fill，即做深度优先遍历，只遍历是'O'的位置，并将所有遍历到的位置都标记成特殊记号;
2. 将所有未遍历到的位置变成'X'；
3. 将特殊记号变回'O';

```CPP
class Solution {
public:
    int n, m;
    void solve(vector<vector<char>>& board) 
    {
        if (board.empty() || board[0].empty())  return;
        //遍历四条边
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')  dfs(board, i, 0);
            if (board[i][m - 1] == 'O')  dfs(board, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')  dfs(board, 0, j);
            if (board[n - 1][j] == 'O')  dfs(board, n - 1, j);
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0 ; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
        return ;
    }
    
    void dfs(vector<vector<char>> &board, int x, int y)
    {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        board[x][y] = '#';
        
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O')
                dfs(board, a, b);
        }
        return ;
    }
};
```