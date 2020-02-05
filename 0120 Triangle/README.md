## 算法1

**(动态规划)*O($n^2$)***

点 (i,j) 的下一行的相邻数字是 (i+1,j) 和 (i+1,j+1) 。

f(i,j) 表示从下往上走到位置 (i,j) 的最小路径和，计算方式/状态转移方程是

f(i,j)=(i,j)+min(f(i+1,j),f(i+1,j+1))<br>
复杂度分析：<br>

直接把 f(i,j) 存在位置 (i,j) 处，不使用额外空间，因此空间复杂度为 O(1) 。

两层for loop，第一次竖着遍历，第二次横着遍历，时间复杂度为O(n2)。


```CPP
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i --)
            for (int j = 0; j < i + 1; j ++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        
        return triangle[0][0];
    }
};
```