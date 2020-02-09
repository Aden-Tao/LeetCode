#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        
        while(n){
            n -= 1;
            char tmp = 'A' + n % 26;
            n /= 26;
            res = tmp + res;
        }
        
        return res;
    }
};

int main(){

    cout << Solution().convertToTitle(701) << endl;
    return 0;
}