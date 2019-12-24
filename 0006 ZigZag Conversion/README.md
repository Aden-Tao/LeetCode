## 算法1


**(找规律) O(n)**

将字符串"PAYPALISHIRING"标记为0 1 2 3 4 5 6 7 8  9 10 11 12 13 14<br>
先画行为4的情形:<br>
```
0     6       12
1   5 7    11 13
2 4   8 10    
3     9
```

再画行为3的情形:<br>
```
0   4   8     12
1 3 5 7 9  11 13
2   6   10    
```
发现规律，对于行数为n的情形：<br>
1. 第一行与最后一行，是公差为2*(n - 1)的等差数列，首项是0和n - 1;
2. 对于中间的行，是两个公差为2(n - 1)的等差数列，首项分别是i 和 2n - i - 2;

```CPP
class Solution {
public:
    string convert(string s, int n) 
    {
        //找规律，第一行与最后一行是等差数列，公差为2*(n-1)
        //其他行为两个等差数列
        if (n == 1)  return s;
        string res;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n-1)
            {
                for (int j = i; j < s.size(); j += 2 * (n - 1))
                    res += s[j];
            }
            else
            {
                for (int j = i, k = 2 * (n - 1) - i; j < s.size() || k < s.size(); j += 2 * (n-1), k += 2 * (n - 1))
                {
                    if (j < s.size())  res += s[j];
                    if (k < s.size())  res += s[k];
                }
            }
        }
        
        return res;
    }
};
```
##算法2

**(按行遍历) O(n)**

1. res[i] += c: 把每个字符c填入对应的行;<br>
2. i += flag: 更新当前c对应的行索引;<br>
3. flag = -flag: 在达到**Z**字形转折点时，执行反向;

```Python
class Solution:

    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2: return s
        res = ["" for _ in range(numRows)]
        i, flag = 0, -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1: flag = -flag
            i += flag
        return "".join(res)
```