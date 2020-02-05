## 算法1

**(哈希) *O(n)***

首先将所有数字放入哈希表，遍历哈希表中的元素，因为要找连续的数字序列，因此可以通过向后枚举相邻的数字（即不断加一），判断后面一个数字是否在哈希表中即可。

为了保证O(n)O(n)的复杂度，为了避免重复枚举序列，因此只对序列的起始数字向后枚举（例如[1,2,3,4]，只对1枚举，2，3，4时跳过），因此需要判断一下是否是序列的起始数字（即判断一下n-1是否在哈希表中）。

```CPP
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int num: nums){
            if(!s.count(num - 1)){
                int l = 1;
                while(s.count(++ num))  l ++;
                res = max(res, l);
            }
        }
        return res;
    }
};
```