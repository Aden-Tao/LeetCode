## 算法1

**(暴力搜索)*O($C^{3}_{n-1}$)***

直接暴力搜索出所有合法方案。<br>
合法的IP地址由四个0到255的整数组成。我们直接枚举四个整数的位数，然后判断每个数的范围是否在0到255。<br>
一共 n个数字，n−1 个数字间隔，相当于从 n−1 个数字间隔中挑3个断点，所以计算量是 O($C^{3}_{n-1}$)。

```CPP
class Solution {
public:
    vector<string> res;
    vector<int> path;
    
    vector<string> restoreIpAddresses(string s) {
        dfs(0, 0, s);
        return res;
    }
    
    // u表示枚举到的字符串下标，k表示当前截断的IP个数，s表示原字符串
    void dfs(int u, int k, string &s)
    {
        if (u == s.size())
        {
            if (k == 4)
            {
                string ip = to_string(path[0]);
                for (int i = 1; i < 4; i ++)
                    ip += '.' + to_string(path[i]);
                res.push_back(ip);
            }
        }
        if (k > 4) return;
        
        unsigned t = 0;
        for (int i = u; i < s.size(); i ++)
        {
            t = t * 10 + s[i] - '0';
            if (t >= 0 && t < 256)
            {
                path.push_back(t);
                dfs(i + 1, k + 1, s);
                path.pop_back();
            }
            if (!t)  break;
        }
    }
};
```

```Python
class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        self.dfs(s, 0, "", res)
        return res
    
    def dfs(self, s, idx, cur, res):
        if idx==4:
            if not s:
                res.append(cur[:-1])
            return
        
        for i in range(1, 4):
            if i <= len(s):
                #choose one digit
                if i == 1: 
                    self.dfs(s[i:], idx+1, cur+s[:i]+".", res)
                #choose two digits, the first one should not be "0"
                elif i == 2 and s[0] != "0": 
                    self.dfs(s[i:], idx+1, cur+s[:i]+".", res)
                #choose three digits, the first one should not be "0", and should less than 256
                elif i == 3 and s[0] != "0" and int(s[:3]) <= 255:
                    self.dfs(s[i:], idx+1, cur+s[:i]+".", res)
```