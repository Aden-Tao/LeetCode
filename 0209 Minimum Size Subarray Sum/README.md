## 算法1

**(双指针)*O(n)***

1. 定义start和end代表当前区间，若[start,end]内的和大于等于s，更新答案后，start向前移动，直到[start,end]内的和不再大于等于s；
2. 然后end每次向后移动一次。

```CPP
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, res = INT_MAX;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum >= s){
                res = min(res, i - start + 1);
                sum -= nums[start++];
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};
```
