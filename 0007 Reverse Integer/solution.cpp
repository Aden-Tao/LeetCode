#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res < INT_MIN || res > INT_MAX) return 0;
        return res;
    }
};

int main()
{
    Solution s;
    assert(s.reverse(123) == 321);
    assert(s.reverse(-123) == -321);
    assert(s.reverse(120) == 21);
    return 0;
}