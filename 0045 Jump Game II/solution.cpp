#include <bits/stdc++.h>

using std:: vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        int g_mx = 0, l_mx = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i ++)
        {
            g_mx = std::max(g_mx, i + nums[i]);
            if (i == l_mx)
            {
                res ++;
                l_mx = g_mx;
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec{2,3,1,1,4};
    assert(Solution().jump(vec) == 2);
    return 0;
}