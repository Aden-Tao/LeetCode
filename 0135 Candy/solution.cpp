#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> f(n, 1);

        for (int i = 1; i < n; i ++)
            if (ratings[i - 1] < ratings[i])
                f[i] = f[i - 1] + 1;
        for (int i = n - 2; i >= 0; i --)
            if (ratings[i] > ratings[i + 1] && f[i] <= f[i + 1])
                f[i] = f[i + 1] + 1;

        int res = 0;
        for (int n : f) res += n;
        return res;
    }
};

int main(){
    vector<int> ratings{1, 0, 2};
    cout << Solution().candy(ratings) << endl;
    return 0;
}