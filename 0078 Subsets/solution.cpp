#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int subset_num = pow(2, n);
        vector<vector<int> > subset (subset_num, vector<int>());
        
        for (auto i = 0; i < n; i ++){
            for (auto j = 0; j < subset_num; j ++){
                if ((j >> i) & 1)
                    subset[j].push_back(nums[i]);
            }
        }
        return subset;
    }
};

int main(){
    Solution s;
    vector<int> vec{1,2,3};
    vector<vector<int>> res = s.subsets(vec);
    for (auto v : res)
    {
        for (int n : v)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}