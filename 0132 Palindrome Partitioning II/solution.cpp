#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<int> f(s.size() + 1);
        f[0] = -1;

        for (int i = 1; i <= s.size(); i ++)
        {
            f[i] = i;
            for (int j = 0; j < i; j ++)
            {
                if (check(s.substr(j, i - j)))
                {
                    if (f[i] > f[j] + 1)
                        f[i] = f[j] + 1;
                }
            }
        }
        return f[s.size()];
    }

    bool check(string a)
    {
        for (int i = 0, j = a.size() - 1; i < j; i ++, j --)
            if (a[i] != a[j])
                return false;
        return true;
    }
};

int main(){
    string s = "aab";
    cout << Solution().minCut(s) << endl;
    return 0;
}