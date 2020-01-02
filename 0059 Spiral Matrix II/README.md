## 算法1

**(循环)*O($n^{2}$)***

类似于[54 Spiral Matrix](../0054&#32;Spiral&#32;Matrix/README.md)

```CPP
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if(n == 0) return res;
        int u = 0, d = n - 1, l = 0, r = n - 1, cnt = 1;
        
        while(true){
            for(int i = l; i <= r; i ++) res[u][i] = cnt ++;
            if(++ u > d) break;
            for(int i = u; i <= d; i ++) res[i][r] = cnt ++;
            if(-- r < l) break;
            for(int i = r; i >= l; i --) res[d][i] = cnt ++;
            if(-- d < u) break;
            for(int i = d; i >= u; i --) res[i][l] = cnt ++;
            if(++ l > r) break;
        }
        return res;
    }
};
```