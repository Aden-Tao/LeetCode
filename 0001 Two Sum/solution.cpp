#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (hash.count(target - nums[i]))
                return vector<int> {hash[target - nums[i]], i};
            hash[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main()
{
    Solution s;
    vector<int> v1{2,7,11,15};
    int a;
    cin >> a;
    assert( (s.twoSum(v1, 9) == vector<int>{0, 1}) );
    return 0;
}