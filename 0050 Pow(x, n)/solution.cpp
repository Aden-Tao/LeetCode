#include <bits/stdc++.h>

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n; i != 0; i /= 2){
            if(i % 2 != 0){
                res *= x;
            }
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};

int main(){
    assert(Solution().myPow(2.00000, 10) == 1024.00000);
    std::cout << Solution().myPow(2.10000, 3) << std::endl;
    return 0;
}