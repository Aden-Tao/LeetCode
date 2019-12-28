#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        for (; i < n - 2; i ++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                if (s == 0)
                {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    l += 1, r -= 1;
                    while (l < r && nums[l] == nums[l - 1])
                        l ++;
                    while (l < r && nums[r] == nums[r + 1])
                        r --;
                }
                else if (s > 0)
                    r --;
                else
                    l ++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec{-1,0,1,2,-1,-4};
    vector<vector<int>> res = s.threeSum(vec);
    for (auto v : res)
    {
        for (auto i: v)
            cout << i << ",";
        cout << "\b" << endl;
    }
    return 0;
}