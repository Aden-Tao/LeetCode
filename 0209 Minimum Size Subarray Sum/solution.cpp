#include "iostream"
#include "vector"
#include "climits"
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // O(n) solution
        int n = nums.size(), start = 0, sum = 0, res = INT_MAX;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum >= s){
                res = min(res, i - start + 1);
                sum -= nums[start++];
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};

int main(){
    int s = 7;
    vector<int> nums = {2,3,1,2,4,3};
    cout << Solution().minSubArrayLen(s, nums) << endl;

    return 0;
}