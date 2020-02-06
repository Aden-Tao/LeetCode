## 算法1

**(暴搜+剪枝)*O($2^n$n)***
暴力枚举所有方案<br>

遍历字符串s中从开始位置到i，如果s[:i+1]是回文串，把S[:i+1]添加到临时数组中，继续dfs其余s[i+1:]。返回的条件是需要dfs的字符串长度为空，此时把这种情况的临时数组添加到最终的结果数组中。

时间复杂度分析：首先考虑最多有多少个合法方案，我们可以考虑在相邻字符之间放板子，每种放板子的方法都对应一种划分方案，而每个字符间隔有放和不放两种选择，所以总共有 $2^(n−1)$ 个方案。另外对于每个方案，需要 O(n)O 的时间记录方案。所以总时间复杂度是 O($2^n$n)。

C++ 代码
```CPP
class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;

    vector<vector<string>> partition(string s) {
        dfs(s);
        return res;
    }

    void dfs(string s)
    {
        if (s.empty())
            res.push_back(cur);
        for (int i = 1; i <= s.size(); i ++)
        {
            if (check(s.substr(0, i)))
            {
                cur.push_back(s.substr(0, i));
                dfs(s.substr(i));
                cur.pop_back();
            }
        }
    }

    bool check(string a)
    {
        for (int i = 0, j = a.size() - 1; i < j; i ++, j --)
        {
            if (a[i] != a[j])
                return false;
        }
        return true;
    }
};
```

```Python
class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        self.res = []
        self.dfs(s, [])
        return self.res
    
    def dfs(self, s, cur):
        if not s:
            self.res.append(cur[:])
        
        for i in range(1, len(s)+1):
            if self.isPali(s[:i]):
                cur.append(s[:i])
                self.dfs(s[i:], cur)
                cur.pop()
            
    def isPali(self, s):
        return s == s[::-1]
```