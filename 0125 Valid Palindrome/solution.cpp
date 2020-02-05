#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())  return true;
        int l = 0, h = s.size()-1;
        while(l < h){
            while(l < h && !isalnum(s[l]))
                l ++;
            while(l < h && !isalnum(s[h]))
                h--;
            if(tolower(s[l]) != tolower(s[h]))
                return false;
            l ++;
            h --;
        }
        return true;
    }
};

int main(){
    string s1 = "A man, a plan, a canal: Panama";
    cout << Solution().isPalindrome(s1) << endl;

    string s2 = "race a car";
    cout << Solution().isPalindrome(s2) << endl;

    return 0;
}