## 算法1

**(原地算法)*O(n)***

1. 遍历二维数组，如果某数为0将其行和列所有其他为不为0的值更改为一个特殊值；
2. 二次遍历将上一轮的特殊值改回为0；

```CPP
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(matrix[i][j] == 0){
                    for(int ii = 0; ii < m; ii ++)
                        if(matrix[ii][j] != 0)
                            matrix[ii][j] = INT_MAX - 1;
                    
                    for(int jj = 0; jj < n; jj ++)
                        if(matrix[i][jj] != 0)
                            matrix[i][jj] = INT_MAX - 1;
                }
            }
        }
        
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j] == INT_MAX-1)
                    matrix[i][j] = 0;
    }
};
```