## 算法1

**(动态规划, DFS枚举) *O($n^3$)***

1. 按照[Word Break](../0139%20Word%20Break/README.md) 的动态规划思路，求出f数组，f[i]表示[0, i]是否可以被完整分割;
2. 根据f数组，从位置n开始进行DFS，枚举所有可能分割的方式。枚举时，只需要判断 f[i] 是否可能从 f[j] 转移过来的，若可能，则递归到位置 j ;

```CPP
class Solution {
public:
    vector<string> res;
    vector<string> cur;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);//dp表示字符之间的隔板，n个字符有n+1个隔板
        dp[0] = true;//dp[0]是s[0]前面的隔板
    
        for (int i = 1; i <= s.size(); i ++)
        {
            for (int j = i; j >= 0; j --)
            {
                if(dict.count(s.substr(j,i - j)) && dp[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        dfs(s.size(), s, dp, dict);
        return res;
    }

    void dfs(int i, string &s, vector<bool> &dp, unordered_set<string> &dict)
    {
        if (i == 0)
        {
            string t = "";
            for (int j = cur.size() - 1; j >= 0; --j)
            {
                t += cur[j];
                if (j > 0) t += " ";
            }
            res.push_back(t);
            return;
        }
        for (int k = i; k >= 0; --k)
        {
            if (dp[k] && dict.count(s.substr(k, i - k)))
            {
                cur.push_back(s.substr(k, i - k));
                dfs(k, s, dp, dict);
                cur.pop_back();
            }
        }
    }
};
```


```Python
class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        words = set(wordDict)
        mem = {}
        
        def wordBreak(s):
            if s in mem:  return mem[s]
            res = []
            if s in words:  res.append(s)
            for i in range(1, len(s)):
                right = s[i:]
                if right not in words:  continue
                res += [w + ' ' + right for w in wordBreak(s[:i])]
            mem[s] = res
            return mem[s]
        
        return wordBreak(s)
```