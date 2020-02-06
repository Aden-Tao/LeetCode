## 算法1

**(动态规划)*O($n^2$)***

用一个bool数组 dp[i] 表示 s[0:i] 是否能被break，例如 dp[1] 表示 s[0:1] 也就是 s[0] 单独一个字母是可以break的。

构造集合unordered_set， 因为题目给的“词典”是vector不是set， 查找起来不好用。
遍历数组 s，判断有没有某个断点jj刚好可以满足 s[j,i] 在词典中
返回 dp[s.size()]，表示 s[0:s.size()] 是否为断点

```CPP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
        return dp[s.size()];
    }
};
```