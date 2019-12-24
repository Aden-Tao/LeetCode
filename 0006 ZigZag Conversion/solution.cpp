#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int n) 
    {
        //找规律，第一行与最后一行是等差数列，公差为2*(n-1)
        //其他行为两个等差数列
        if (n == 1)  return s;
        string res;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n-1)
            {
                for (int j = i; j < s.size(); j += 2 * (n - 1))
                    res += s[j];
            }
            else
            {
                for (int j = i, k = 2 * (n - 1) - i; j < s.size() || k < s.size(); j += 2 * (n-1), k += 2 * (n - 1))
                {
                    if (j < s.size())  res += s[j];
                    if (k < s.size())  res += s[k];
                }
            }
        }
        
        return res;
    }
};

int main ()
{
    Solution s;
    assert(s.convert("LEETCODEISHIRING", 3) == "LCIRETOESIIGEDHN");
    return 0;
}