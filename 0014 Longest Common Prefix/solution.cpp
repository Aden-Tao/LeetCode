#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)  return "";
        
        string prefix = strs[0];
        for (int i = 0; i < prefix.size(); i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (i > strs[j].size() - 1 || prefix[i] != strs[j][i])
                    return prefix.substr(0, i);
            }
        }
        return prefix;
    }
};


int main(){
    Solution s;
    vector<string> vec = {"flower","flow","flight"};
    assert(s.longestCommonPrefix(vec) == "fl");
    return 0;
}