#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i ++ )
            res += max(0, prices[i] - prices[i - 1]);
        return res;
    }
};

int main(){
    vector<int> p1{7,1,5,3,6,4};
    cout << Solution().maxProfit(p1) << endl;

    vector<int> p2{1,2,3,4,5};
    cout << Solution().maxProfit(p2) << endl;

    return 0;
}