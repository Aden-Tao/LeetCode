## 算法1

**(投票算法)*O(n)***

1. 定义cnt计数器，初始为1, res记录答案;
2. 从头开始遍历数组，若发现 cnt<0 ，则  res=nums[i]；然后若 res==nums[i]，cnt++；否则cnt--;
3. 遍历结束后，若数组中存在主要元素，则主要元素必定是 res;

```CPP
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == res)
                cnt++;
            else
                cnt--;
        
            if(cnt < 0)
                res = nums[i], cnt = 1;
        }
        
        return res;
    }
};
```