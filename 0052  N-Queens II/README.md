## 算法1

**(回溯，暴力枚举)*O(n)***

```CPP
 class Solution {
public:
    int res = 0, N;
    vector<bool> col, d1, d2;
    
    int totalNQueens(int n) {
        N = n;
        col = vector<bool>(n, false);
        d1 = d2 = vector<bool> (n * 2, false);
        
        dfs(0);
        return res;
    }
    
    void dfs(int row)
    {
        if (row == N) 
        {
            res ++;
            return;
        }
        for (int c = 0; c < N; c ++ )
        {
            if (!col[c] && !d1[row + c] && !d2[row - c + N])
            {
                col[c] = d1[row + c] = d2[row - c + N] = true;
                dfs(row + 1);
                col[c] = d1[row + c] = d2[row - c + N] = false;
            }
        }
    }
};
```