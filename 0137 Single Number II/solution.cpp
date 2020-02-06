#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int bit = 0; bit < 32; bit ++)
        {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i ++)
                cnt += (nums[i] >> bit) & 1;
            res += (cnt % 3) << bit;
        }
        return res;
    }
};

int main(){
    vector<int> nums{2,2,3,2};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}