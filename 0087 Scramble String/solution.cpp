#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        string ss1 = s1, ss2 = s2;
        sort(ss1.begin(), ss1.end()), sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) return false;
        for (int i = 1; i < s1.size(); i ++ )
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
                    && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i))
                    && isScramble(s1.substr(i), s2.substr(0, s2.size() - i)))
                return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    assert(s.isScramble("great", "rgeat") == true);
    assert(s.isScramble("abcde", "caebd") == false);
    return 0;
}