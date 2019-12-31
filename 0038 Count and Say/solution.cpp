#include <bits/stdc++.h>
using std::string;

class Solution {
public:
    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 1; i < n; i++)
        {
            string t = "";
            for (int j = 0; j < s.size(); j++)
            {
                int cnt = 1;
                while (j + 1 < s.size() && s[j] == s[j + 1])
                {
                    cnt ++, j++;
                }
                
                t += std::to_string(cnt) + s[j];

            }
            s = t;
        }
        return s;
    }
};

int main(){
    Solution s;
    assert(Solution().countAndSay(4) == "1211");
    return 0;
}