#include <bits/stdc++.h>
using namespace std;

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

int main(){
    vector<vector<char>> board{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'X', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}
        };

    Solution().solve(board);
    for (auto v : board)
    {
        for (char c : v)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}