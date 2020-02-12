#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i ++){
            res <<= 1;
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
};

int main(){

    int n = 43261596;
    cout << Solution().reverseBits(n) << endl;

    return 0;
}