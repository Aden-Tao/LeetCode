#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return 0;
        vector<int> f(n + 1, 0), g(n + 1, 0);
        for (int i = 1; i <= n; i ++)
        {
            g[i] = max (g[i - 1], f[i - 1]);
            f[i] = g[i - 1] + nums[i - 1];
        }
        
        return max(f[n], g[n]);
    }
};

int main(){

    vector<int> nums{1,2,3,1};
    cout << Solution().rob(nums) << endl;
    return 0;
}