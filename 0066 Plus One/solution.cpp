#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i --)
        {
            if (digits[i] < 9)
            {
                digits[i] ++;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> res(digits.size() + 1);
        res[0] = 1;
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec{1,2,3};
    vector<int> res{1,2,4};
    assert(s.plusOne(vec) == res);
    
    return 0;
}