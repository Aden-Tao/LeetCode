#include<bits/stdc++.h>
using namespace std;

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

int main(){
    string s = "catsanddog";
    vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
    for (auto s : Solution().wordBreak(s, wordDict))
        cout << s << endl;

    return 0;
}