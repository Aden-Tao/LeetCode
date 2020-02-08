#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int pos[size], neg[size];
        
        int res = nums[0];
        pos[0] = neg[0] = nums[0];
        
        for(int i = 1; i < size; i ++){
            pos[i] = max( max(pos[i-1]*nums[i], neg[i-1]*nums[i]), nums[i] );
            neg[i] = min( min(pos[i-1]*nums[i], neg[i-1]*nums[i]), nums[i] );
            
            res = max(pos[i], res);
        }
        
        return res;
    }
};

int main(){
    vector<int> nums{2,3,-2,4};
    cout << Solution().maxProduct(nums) << endl;

    return 0;
}