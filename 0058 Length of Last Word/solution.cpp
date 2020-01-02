#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int sum = 0, res = 0;
        for (int i = 0; i < s.size(); i ++ )
            if (s[i] == ' ')
            {
                if (sum) res = sum;
                sum = 0;
            }
            else
                sum ++ ;
        if (sum) res = sum;
        return res;
    }
};

int main(){
    Solution s;
    assert(s.lengthOfLastWord("Hello World") == 5);
    return 0;
}