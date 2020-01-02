#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        for (int i = 1; i <= n; i ++) num.push_back(i);
        
        vector<int> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i ++)  fact[i] = i * fact[i - 1];
        
        k --;
        string res = "";
        for (int i = n; i > 0; i --)
        {
            int idx = k / fact[i - 1];
            k = k % fact[i - 1];
            res.push_back(num[idx] + '0');
            num.erase(num.begin() + idx);
        }
        return res;
    }
};

int main(){
    Solution s;
    assert(s.getPermutation(3,3) == "213");
    return 0;
}