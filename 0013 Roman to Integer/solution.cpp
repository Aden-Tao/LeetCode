#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length(), ans = 0;
        unordered_map<char, int> words;
        words['I'] = 1; words['V'] = 5;
        words['X'] = 10; words['L'] = 50; 
        words['C'] = 100; words['D'] = 500;
        words['M'] = 1000;
        for (int i = 0; i < n; i++) {
            if (i != n - 1 && words[s[i + 1]] > words[s[i]]) {
                ans += words[s[i + 1]] - words[s[i]];
                i++;
            }
            else
                ans += words[s[i]];
        }
        return ans;
    }
};

int main(){

    assert(Solution().romanToInt("IV") == 4);
    return 0;
}