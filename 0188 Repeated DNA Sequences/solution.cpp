#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        
        int n = prices.size();
        if (k >= n / 2)  return stock2(prices);
        
        vector<int> local(k + 1);
        vector<int> global(k + 1);
        
        for (int i = 1; i < n; i ++)
        {
            int diff = prices[i] - prices[i - 1];
        
            for (int j = k; j  > 0; j --)
            {
                local[j] = max(global[j - 1], local[j] + diff);
                global[j] = max(global[j], local[j]);

            }
        }
        return global[k];
    }
    
    int stock2(vector<int> &p)
    {
        int res = 0;
        for (int i = 1; i < p.size(); i ++)
            res += max(0, p[i] - p[i - 1]);
        return res;
    }
};           

int main(){

    vector<int> prices{3,2,6,5,0,3};
    int k = 2;
    cout << Solution().maxProfit(k, prices) << endl;
    return 0; 
}