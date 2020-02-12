## 算法1

**(dfs)*O(nm)***

1. 从任意一个陆地点开始，即可通过四连通的方式，深度优先搜索遍历到所有与之相连的陆地，即遍历完整个岛屿；遍历结束后将遍历过的点清0;
2. 重复以上过程，记录起点的个数即可;

```CPP
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty() || grid[0].empty())  return 0;
        
        int n = grid.size(),  m = grid[0].size();
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == '1')
                dfs(grid, a, b);
        }
    }
};
```