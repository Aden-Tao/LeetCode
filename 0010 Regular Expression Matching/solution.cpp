#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        s = " " + s;
        p = " " + p;
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (i > 0 && (s[i] == p[j] || p[j] == '.'))
                    f[i][j] = f[i][j] | f[i - 1][j - 1];
                if (p[j] == '*') {
                    if (j >= 2)
                        f[i][j] = f[i][j] | f[i][j - 2];
                    if (i > 0 && (s[i] == p[j - 1] || p[j - 1] == '.'))
                        f[i][j] = f[i][j] | f[i - 1][j];
                }
            }
        return f[n][m];
    }
};

int main(){
    Solution s;
    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "a*") == true);
    assert(s.isMatch("ab", ".*") == true);
    assert(s.isMatch("mississippi", "mis*is*p*.") == false);
    return 0;
}