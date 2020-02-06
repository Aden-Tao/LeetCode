#include<bits/stdc++.h>
using namespace std;

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

int main(){
    string s = "leetcode";
    vector<string> wordDict{"leet", "code"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}