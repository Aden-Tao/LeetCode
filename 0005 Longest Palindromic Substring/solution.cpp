#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            //最长回文子串长度为奇数
            for (int j = i, k = i; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
                if (res.size() < k - j + 1)
                    res = s.substr(j, k - j + 1);
            
            //最长回文子串长度为偶数
            for (int j = i, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++)
                if (res.size() < k - j + 1)
                    res = s.substr(j, k - j + 1);
        }
        
        return res;
    }
};

int main(){
    Solution s;
    assert(s.longestPalindrome("babad") == "bab");
    assert(s.longestPalindrome("cbbd") == "bb");
    return 0;
}