#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n){
            n /= 5;
            res += n;
        }
        
        return res;
    }
};

int main(){
    cout << Solution().trailingZeroes(5) << endl;
    return 0;
}