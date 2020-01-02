## 算法1

**(贪心)*O(n)***

用```g_mx```记录最远可到距离，当 ```i``` 严格大于 ```g_mx```时返回 ```false```, 当```for```循环成功结束意味着每个位置均可以到达，返回```true```;

```CPP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int g_mx = 0;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (i > g_mx)
                return false;
            g_mx = max(g_mx, i + nums[i]);
           
        }
        return true;
    }
};
```