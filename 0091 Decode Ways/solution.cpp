#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i ++)
        {
            if (s[i - 1] != '0')
                f[i] += f[i - 1];
            if (i >= 2)
            {
                int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (t >= 10 && t <= 26)
                    f[i] += f[i - 2];
            }
        }
        return f[n];
    }
};

int main(){
    Solution s;
    assert(s.numDecodings("12") == 2);
    assert(s.numDecodings("226") == 3);

    return 0;
}