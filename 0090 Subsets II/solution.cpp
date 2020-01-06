#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty())  return {};
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        
        int size = 1, last = nums[0];
        for (int i = 0; i < nums.size(); i ++)
        {
            if (last != nums[i])
            {
                last = nums[i];
                size = res.size();
            }
            
            int totalSize = res.size();
            for (int j = totalSize - size; j < totalSize; j ++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec{1,2,2};;
    vector<vector<int>> res = s.subsetsWithDup(vec);
    for (auto v : res)
    {
        for (auto n : v)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}