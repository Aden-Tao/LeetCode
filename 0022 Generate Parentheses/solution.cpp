#include <bits/stdc++.h>

using std:: vector; using std:: string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", n, n, res);
        return res;
    }
    
    void dfs(string s, int left, int right, vector<string> &res){
        if(left > right)  return ;
        if(left == 0 && right == 0)
            res.push_back(s);
        if(left>0)
            dfs(s+'(', left-1, right, res);
        if(right>0)
            dfs(s+')', left, right-1, res);
    }
};

int main(){
    Solution s;
    for (auto str: s.generateParenthesis(3))
        std::cout << str << std::endl;
    return 0;
}