## 算法1

**(递推)*O($n^2$)***

从上到下依次计算每一行；
对于每一行，先把1放在首位两个位置，然后计算中间的数：f[i][j] = f[i-1][j-1] + f[i-1][j];

```Python
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        for row in range(0, numRows):
            cur = [None for _ in range(row+1)]
            cur[0] = cur[-1] = 1
            
            for j in range(1, len(cur) - 1):
                cur[j] = res[row - 1][j - 1] + res[row - 1][j]
                
            res.append(cur)
            
        return res
```