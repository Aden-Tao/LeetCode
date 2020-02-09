#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        vector<int> res(2);
        while (l < r)
        {
            if (nums[l] + nums[r] > target )
                r --;
            else if (nums[l] + nums[r] < target)
                l ++;
            else
            {
                res[0] = l + 1;
                res[1] = r + 1;
                break;
            }   
        }
        return res;
    }
};

int main(){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    for (int n : Solution().twoSum(numbers, target))
        cout << n << " ";
    return 0;
}