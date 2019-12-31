## 算法1

**(分解操作*O($n^{2})$***

直接将它分解成两个操作：
1. 先以左上-右下对角线为轴做翻转；
2. 再以中心竖线为轴做反转;

```CPP
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)  return ;
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < i; j ++)
                swap(matrix[i][j], matrix[j][i]);
        
        for (int i = 0; i < n; i ++)
            for (int j = 0, k = n - 1; j < k; j ++, k --)
                swap(matrix[i][j], matrix[i][k]);
        return ;
    }
};
```
