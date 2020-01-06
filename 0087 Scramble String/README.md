## 算法1

**(暴力搜索)*O($5^{n}$)***

递归判断两个字符串是否可以相互转化。

首先判断两个字符串的字符集合是否相同，如果不同，则两个字符串一定不可以相互转化。<br>
然后枚举第一个字符串左半部分的长度，分别递归判断两种可能的情况：

* 该节点不发生翻转，则分别判断两个字符串的左右两部分是否分别可以相互转化；
* 该节点发生翻转，则分别判断第一个字符串的左边是否可以和第二个字符串的右边相互转化，且第一个字符串的右边可以和第二个字符串的左边相互转化；

```CPP
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        string ss1 = s1, ss2 = s2;
        sort(ss1.begin(), ss1.end()), sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) return false;
        for (int i = 1; i < s1.size(); i ++ )
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                    && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i))
                    && isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))
                return true;
        }
        return false;
    }
};
```
