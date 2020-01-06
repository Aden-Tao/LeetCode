## 算法1

**(DFS)*O($n^{2}$$3^{k}$)***

1. 先枚举单词的起点，然后依次枚举单词的每个字母。
2. 过程中需要将已经使用过的字母改成一个特殊字母，以避免重复使用字符。

```CPP
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
```
