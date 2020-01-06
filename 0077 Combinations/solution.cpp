#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combine(int n, int k) {

        dfs(n, k, 1);
        return res;
    }
    
private:
    void dfs(int n, int k, int idx){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        for(int i = idx; i <= n; i ++){
            cur.push_back(i);
            dfs(n, k, i + 1);
            cur.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);
    for (auto v : res)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}