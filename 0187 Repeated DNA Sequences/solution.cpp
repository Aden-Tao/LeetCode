#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        
        vector<string> res;
        for (int i = 0; i + 10 <= s.size(); i ++)
        {
            string str = s.substr(i, 10);
            hash[str] ++;
            if (hash[str] == 2) 
                res.push_back(str);
        }
        return res;
    }
};

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = Solution().findRepeatedDnaSequences(s);
    for (auto t : res)
        cout << t << " ";

    return 0;
}