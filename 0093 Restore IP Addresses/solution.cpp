#include <bits/stdc++.h>
using namespace std;

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

int main(){
    Solution s;
    string str = "25525511135";
    cout << "[";
    for (auto s : s.restoreIpAddresses(str))
        cout << s <<",";
    cout << "\b"; 
    cout << "]";
    return 0;
}