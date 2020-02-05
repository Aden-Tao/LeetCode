#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n)  return 0;
        vector<int> f(n, 0);
        
        int preMin = INT_MAX;
        for (int i = 0; i < n; i ++)
        {
            if (i)  f[i] = f[i - 1];
            if (prices[i] > preMin)
                f[i] = max(f[i], prices[i] - preMin);
            preMin = min(preMin, prices[i]);
        }
        
        vector<int> g(n, 0);
        int postMax = INT_MIN;
        for (int i = n - 1; i >= 0; i --)
        {
            if (prices[i] < postMax)
                g[i] = max(g[i], postMax - prices[i]);
            postMax = max(postMax, prices[i]);
        }
        
        int res  = 0;
        for (int i = 0; i < n; i ++)
            res = max(res, f[i] + g[i]);
        return res;
    }
};

int main(){
    vector<int> p1{3,3,5,0,0,3,1,4};
    cout << Solution().maxProfit(p1) << endl;

    vector<int> p2{1,2,3,4,5};
    cout << Solution().maxProfit(p2) << endl;

    return 0;
}