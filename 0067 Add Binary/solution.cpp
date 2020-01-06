#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1;
        int c = 0;
        while (i >= 0 || j >= 0)
        {
            int t = c;
            if (j >= 0) t += b[j --] - '0';
            if (i >= 0) t += a[i --] - '0';
            res += to_string(t % 2);
            c = t / 2;
        }
        if (c != 0) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){

    assert(Solution().addBinary("11", "1") == "100");
    return 0;
}