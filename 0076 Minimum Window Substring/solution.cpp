#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hh;
        
        for(char c : t)  hh[c] ++;
        
        int tot = t.size();
        int l = 0, r = 0;
        int len = INT_MAX, head;
        
        while (r < s.size())
        {
            if (hh[s[r ++]] -- > 0)
                tot --;
            while (tot == 0)
            {
                if (r - l < len)
                {
                    len = r - l;
                    head = l;
                }
                
                if (hh[s[l ++]] ++ == 0)
                    tot ++;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};

int main(){
    Solution s;
    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");

    return 0;
}