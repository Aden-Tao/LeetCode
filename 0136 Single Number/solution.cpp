#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto n : nums)
            res ^= n;
        
        return res;
    }
};

int main(){
    vector<int> nums{4,1,2,1,2};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}