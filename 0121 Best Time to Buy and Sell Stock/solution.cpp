#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        int res = 0, lowest = prices[0];
        for (int p : prices)
        {
            res = max(res, p - lowest);
            if (p < lowest)  lowest = p;
            
        }
        return res;
    }
};

int main(){
    vector<int> prices{7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;

    vector<int> prices2{7,6,4,3,1};
    cout << Solution().maxProfit(prices2) << endl;

    return 0;
}