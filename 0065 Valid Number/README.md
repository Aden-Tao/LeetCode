## 算法1 

**(模拟 字符串处理)*O(n)***

1. 先去除行首和行尾空格；
2. 行首如果有一个正负号，直接忽略；
3. 如果字符串为空或只有一个'.'，则不是一个合法数；
4. 循环整个字符串，去掉以下几种情况：
    1.  '.'或'e'多于1个;
    2.  '.'在'e'后面出现；
    3.  'e'后面或前面为空，或者'e'前面紧跟着'.'；
    4.  'e'后面紧跟着正负号，但正负号后面为空；
5. 剩下的情况都合法；

```CPP
class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') i ++ ;
        int j = s.size() - 1;
        while (j >= 0 && s[j] == ' ') j -- ;
        if (i > j) return false;
        s = s.substr(i, j - i + 1);

        if (s[0] == '-' || s[0] == '+') s = s.substr(1);
        if (s.empty() || s[0] == '.' && s.size() == 1) return false;

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i ++ )
        {
            if (s[i] >= '0' && s[i] <= '9');
            else if (s[i] == '.')
            {
                dot ++ ;
                if (e || dot > 1) return false;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                e ++ ;
                if (i + 1 == s.size() || !i || e > 1 || i == 1 && s[0] == '.') return false;
                if (s[i + 1] == '+' || s[i + 1] == '-')
                {
                    if (i + 2 == s.size()) return false;
                    i ++ ;
                }
            }
            else return false;
        }
        return true;
    }
};
```