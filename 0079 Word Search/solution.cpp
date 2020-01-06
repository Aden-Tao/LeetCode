#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())  return false;
        
        n = board.size(), m = board[0].size();
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                if (dfs(board, i, j, word, 0))
                    return true;
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int u)
    {
        if (board[x][y] != word[u])  return false;
        if (u == word.size() - 1)  return true;
        
        board[x][y] = '.';
        for (int i = 0; i < 4; i ++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m)
                if (dfs(board, a, b, word, u + 1))
                    return true;
        }
        board[x][y] = word[u];
        
        return false;
    }
};

int main(){

    Solution s;
    vector<vector<char>> board = {
        {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}
    };
    assert(s.exist(board, "SEE") == true);
    assert(s.exist(board, "ABCCED") == true);
    assert(s.exist(board, "ABCB") == false);
    return 0;
}