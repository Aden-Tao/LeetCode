## 算法1

**(动态规划)*O($n^2$)***

状态表示：f[i][j]表示 s1 的前 i 个字符和 s2 的前 j 个字符是否可以交错组成 s3 的前 i+j 个字符。<br>
状态转移：如果 s3[i+j] 匹配 s1[i]，则问题就转化成了 f[i−1][j]；如果 s3[i+j] 匹配 s2[j]，则问题就转化成了 f[i][j−1]。两种情况只要有一种为真，则 f[i][j] 就为真。

```CPP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        
        if(l1 + l2 != l3)  return false;
        
        bool table[l1 + 1][l2 + 1];
        
        for(int i = 0; i < l1 + 1; i++){
            for(int j = 0; j < l2 + 1; j++){
                if(i == 0 && j == 0)  table[i][j] = true;
                else if(i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1]==s3[i + j - 1]);
                else if(j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1]==s3[i + j - 1]); 
                else
                    table[i][j] = (table[i - 1][j] && s1[i - 1]==s3[i  + j - 1]) || (table[i][j - 1] && s2[j - 1]==s3[i + j - 1]);
            }
        } 
        return table[l1][l2];
    }
};
```
