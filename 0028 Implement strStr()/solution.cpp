#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        int m=haystack.size(), n=needle.size();
        for(int i=0; i<m-n+1; i++){
            for(int j=0; j<n; j++){
                if(haystack[i+j]!=needle[j])
                    break;
                if(j==n-1)
                    return i;
            }
        }
        return -1;
    }
};

int main(){
    assert(Solution().strStr("hello", "ll") == 2);
    return 0;
}