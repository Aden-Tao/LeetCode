## 算法1

**(贪心算法)*O(n)***

每次在可跳范围内选择可以使得跳的更远的位置

```CPP
class Solution {
public:
    int jump(vector<int>& nums) {
        int g_mx = 0, l_mx = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i ++)
        {
            //找能跳的最远的
            g_mx = max(g_mx, i + nums[i]);
            if (i == l_mx) // 如果遇到边界，就更新边界，并且步数加1
            {
                res ++;
                l_mx = g_mx;
            }
        }
        return res;
    }
};
```