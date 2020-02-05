#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //The basic idea is to iteratively update the array from the end to the beginning.
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for(int i = 1; i<=rowIndex; i++){
            for(int j = i; j>=1; j--){
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};

int main(){

    vector<int> res = Solution().getRow(5);
    for (int n : res)
        cout << n << " ";
}