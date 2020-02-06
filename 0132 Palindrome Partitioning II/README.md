## 算法1

**(动态规划) *O($n^2$)***

状态表示： f[i] 表示前 i 个字符组成的子串，最少需要几次分割才能变成回文串；

转移方程： 对于所有 j < i ,如果 s[j, i]是回文串，且 f[j] + 1 < f[i], 则 f[i] = f[j] + 1;

初始化： f[i] = i - 1, 长度为 i 的子串，最多切 i - 1 次会全变为回文串；

 ```CPP
class Solution {
public:
    int minCut(string s) {
        vector<int> f(s.size() + 1);
        f[0] = -1;

        for (int i = 1; i <= s.size(); i ++)
        {
            f[i] = i;
            for (int j = 0; j < i; j ++)
            {
                if (check(s.substr(j, i - j)))
                {
                    if (f[i] > f[j] + 1)
                        f[i] = f[j] + 1;
                }
            }
        }
        return f[s.size()];
    }

    bool check(string a)
    {
        for (int i = 0, j = a.size() - 1; i < j; i ++, j --)
            if (a[i] != a[j])
                return false;
        return true;
    }
};
 ```