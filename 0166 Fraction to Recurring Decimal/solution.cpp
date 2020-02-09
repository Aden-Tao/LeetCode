#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)  return "0";
        string res;
        
        if(numerator<0 ^ denominator<0)  res += '-';
        
        long long int n = labs(numerator);
        long long int d = labs(denominator);
        
        res += to_string(n / d); //添加整数部分
        if(n % d == 0)
            return res;
        res += '.';
        unordered_map<int, int> mp;
        
        for(long long int r = n % d; r; r %= d){
            if(mp.count(r) > 0){
                res.insert(mp[r], 1, '(');
                res.push_back(')');
                break;
            }
            mp[r] = res.size();
            r *= 10;
            res += to_string(r/d);
        }
        return res;
    }
};

int main(){
    int numerator = 2, denominator = 3;
    cout << Solution().fractionToDecimal(numerator, denominator) << endl;

    return 0;
}