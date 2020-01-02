## 算法1

**(遍历)*O(n)***

定义两个变量：res, sum，分别表示当前最后一个单词（已遍历完）的长度，以及当前单词（正在遍历，但还没遍历完）的长度<bt>

然后遍历字符串:

1. 如果遇到非空格字符，让 sum 加1；
2. 如果遇到空格，判断sum是否为0，如果大于0，说明已经遍历完一个新单词，清空sum，更新res;


```CPP
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sum = 0, res = 0;
        for (int i = 0; i < s.size(); i ++ )
            if (s[i] == ' ')
            {
                if (sum) res = sum;
                sum = 0;
            }
            else
                sum ++ ;
        if (sum) res = sum;
        return res;
    }
};
```