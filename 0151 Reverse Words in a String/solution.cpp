#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); i ++)
        {
            while (i < s.size() && s[i] == ' ')  i ++;
            if (i == s.size())  break;
            int j = i;
            while (j < s.size() && s[j] != ' ')  j ++;
            reverse(s.begin() + i, s.begin() + j);
            
            if (k > 0)
                s[k ++] = ' ';
            
            while (i < j)
                s[k ++] = s[i ++];
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(){
    string s = "the sky is blue";
    cout << Solution().reverseWords(s) << endl;
    return 0;
}