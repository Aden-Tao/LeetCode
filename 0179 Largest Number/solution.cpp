#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> S;
        for(int i: nums)
            S.push_back(to_string(i));
        sort(S.begin(), S.end(), [](string &a, string &b){ return a + b > b + a; });
        string res;
        
        for(string s:S)
            res += s;
        
        // to exclude [0, 0] 
        while(res[0] == '0' && res.length() > 1)
            res.erase(0, 1);
        
        return res;
    }
};

int main(){
    vector<int> nums{3,30,34,5,9};
    cout << Solution().largestNumber(nums) << endl;
    return 0;
}