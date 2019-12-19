## 算法1

**(哈希表) O(n)**

使用C++中的哈希表 ———— _unordered_map<int, int> hash_ 

遍历一遍nums数组，同时做两件事：
1. 判断*target\-nums\[i\]* 是否在哈希表中；
2. 将*nums[i]* 插入到哈希表中；
   
**CPP代码**
``` CPP
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
```

**Python代码**
``` Python
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for index, num in enumerate(nums):
            if num in dic:
                return [dic[num], index]
            dic[target - num] = index
```