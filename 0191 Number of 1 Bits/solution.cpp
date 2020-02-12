#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n)
        {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

int main(){

    cout << Solution().hammingWeight(11) << endl;
    return 0;
}