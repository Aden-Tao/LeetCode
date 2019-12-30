#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty())  return res;
        if (words[0].size() == 0) return res;
        int len = s.size(), n = words.size(), m = words[0].size();
        unordered_map<string, int> mp;
        for (string w : words)
            mp[w] ++;
        
        for (int i = 0; i <= len - n * m; i ++)
        {
            unordered_map<string, int> tmp;
            int j = 0;
            for (; j < n; j ++)
            {
                string st = s.substr(i + j * m, m);
                tmp[st] ++;
                if (!mp[st] || tmp[st] > mp[st])
                    break;
            }
            if (j == n)
                res.push_back(i);
        }
        return res;
    }
};

int main(){
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    for (int n : Solution().findSubstring(s, words))
        cout << n << " ";
    return 0;
}