#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int num: nums){
            if(!s.count(num - 1)){
                int l = 1;
                while(s.count(++ num))  l ++;
                res = max(res, l);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}