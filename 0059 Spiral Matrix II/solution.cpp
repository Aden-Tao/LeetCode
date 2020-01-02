#include <bits/stdc++.h>
using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if(n == 0) return res;
        int u = 0, d = n - 1, l = 0, r = n - 1, cnt = 1;
        
        while(true){
            for(int i = l; i <= r; i ++) res[u][i] = cnt ++;
            if(++ u > d) break;
            for(int i = u; i <= d; i ++) res[i][r] = cnt ++;
            if(-- r < l) break;
            for(int i = r; i >= l; i --) res[d][i] = cnt ++;
            if(-- d < u) break;
            for(int i = d; i >= u; i --) res[i][l] = cnt ++;
            if(++ l > r) break;
        }
        return res;
    }
};

int main(){
    Solution s;
    for (auto v : s.generateMatrix(3))
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}