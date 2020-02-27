#include "iostream"
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        for(; m != n; i++){
            m >>= 1;
            n >>= 1;
        }
        return n << i;
    }
};

int main(){

    cout << Solution().rangeBitwiseAnd(5,7) << endl;
    return 0;
}