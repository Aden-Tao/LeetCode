#include <bits/stdc++.h>
using std::string; using std::vector;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> a(n), b(m), c(n + m);
        
        for (int i = 0; i < n; i ++)
            a[n - 1 - i] = num1[i] - '0';
        for (int i = 0; i < m; i ++)
            b[m - 1 - i] = num2[i] - '0';
        
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
            {
                c[i + j] += a[i] * b[j];
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
        
        int l = c.size() - 1;
        while (l > 0 && c[l] == 0)
            l--;
        
        string res = "";
        for (int i = l; i >= 0; i --)
            res += c[i] + '0';
        return res;
    }
};

int main(){
    Solution s;
    assert(s.multiply("123", "456") == "56088");
    return 0;
}