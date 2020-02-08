## 算法1

**(数组翻转) *O(n)***

分两步操作：

1. 将字符串中的每个单词逆序，样例输入变为: "eht yks si eulb"；
2. 将整个字符串逆序，样例输入变为："blue is sky the"；

```CPP
class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i ++)
        {
            while (i < s.size() && s[i] == ' ')  i ++;
            if (i == s.size())  break;
            int j = i;
            while (j < s.size() && s[j] != ' ')  j ++;
            reverse(s.begin() + i, s.begin() + j);
            
            if (k > 0)
                s[k ++] = ' ';
            
            while (i < j)
                s[k ++] = s[i ++];
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};
```