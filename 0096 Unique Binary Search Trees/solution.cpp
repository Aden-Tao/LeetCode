#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> f (n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 0; j < i; j ++)
                f[i] += f[j] * f[i - j - 1];
        }
        
        return f[n];
    }
};

int main(){
    Solution s;
    assert(s.numTrees(3) == 5);
    return 0;
}