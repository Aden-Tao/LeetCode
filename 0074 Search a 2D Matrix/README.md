## 算法1

**(二分)*O(logn)***

把整个矩阵，按行展开成一个一维数组，那么这个一维数组单调递增，然后直接二分即可。
二分时可以通过整除和取模运算得到二维数组的坐标。

```CPP
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())  return false;
        
        int n = matrix.size(), m = matrix[0].size(); 
        int l = 0, r = m * n - 1;
        while (l < r)
        {
            int mid = l + r  >> 1;
            if (matrix[mid / m][mid % m] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        
        return matrix[r / m][r % m] == target? true: false;
    }
};
```
