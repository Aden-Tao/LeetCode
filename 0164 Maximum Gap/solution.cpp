#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)  return 0;
        int N = nums.size();
        int maxNum = INT_MIN, minNum = INT_MAX;
        for (int n : nums)
        {
            maxNum = max(maxNum, n);
            minNum = min(minNum, n);
        }
        if (maxNum == minNum)  return 0;

        double len = 1.0 * (maxNum - minNum) / (N - 1);
        int size = floor((maxNum - minNum) / len) + 1;

        vector<int> bucketMax(size, INT_MIN);
        vector<int> bucketMin(size, INT_MAX);

        for (int n : nums)
        {
            int idx = floor((n - minNum)/len);
            bucketMax[idx] = max(bucketMax[idx], n);
            bucketMin[idx] = min(bucketMin[idx], n);
        }

        int res = 0, preMax = bucketMax[0];
        for (int i = 1; i < size; i ++)
        {
            if (bucketMin[i] != INT_MAX)
            {
                res = max(res, bucketMin[i] - preMax);
                preMax = bucketMax[i];
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums{1,1,1,1,1,5,5,5,5,5};
    cout << Solution().maximumGap(nums) << endl;
    return 0;
}