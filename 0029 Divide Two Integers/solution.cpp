#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)  return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)  return INT_MAX;
        
        long long m = abs((long)dividend), n = abs((long)divisor);
        long long res = 0;
        
        while (m >= n)
        {
            long long t = n, shift = 1;
            while (2 * t <= m)
            {
                t *= 2;
                shift *= 2;
            }
            res += shift;
            m -= t;
        }
        return (dividend > 0) ^ (divisor > 0) ? -res : res;
    }
};

int main(){
    assert(Solution().divide(10, 3) == 3);
    return 0;
}