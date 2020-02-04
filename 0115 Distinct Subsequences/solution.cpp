#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1));

        for (int i = 0; i <= n; i ++)  f[i][0] = 1;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= m; j ++)
            {
                if (s[i - 1] == t[j - 1])
                    f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
                else
                    f[i][j] = f[i - 1][j];
            }
        }
        return f[n][m];
    }
};

int main(){
    string S = "rabbbit", T = "rabbit";
    cout << Solution().numDistinct(S, T);
    return 0;
}