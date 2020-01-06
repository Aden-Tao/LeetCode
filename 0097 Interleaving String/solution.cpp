#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        
        if(l1 + l2 != l3)  return false;
        
        bool table[l1 + 1][l2 + 1];
        
        for(int i = 0; i < l1 + 1; i++){
            for(int j = 0; j < l2 + 1; j++){
                if(i == 0 && j == 0)  table[i][j] = true;
                else if(i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1]==s3[i + j - 1]);
                else if(j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1]==s3[i + j - 1]); 
                else
                    table[i][j] = (table[i - 1][j] && s1[i - 1]==s3[i  + j - 1]) || (table[i][j - 1] && s2[j - 1]==s3[i + j - 1]);
            }
        } 
        return table[l1][l2];
    }
};

int main(){
    Solution s;
    assert(s.isInterleave("aabcc", "dbbca", "aadbbcbcac") == true);
    assert(s.isInterleave("aabcc", "dbbca", "aadbbbaccc") == false);
    return 0;
}