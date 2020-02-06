#include <bits/stdc++.h>
using namespace std;

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

int main(){
    string s = "aab";
    vector<vector<string>> res = Solution().partition(s);
    for (auto v : res)
    {
        for (auto s : v)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}