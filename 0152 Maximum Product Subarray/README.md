## 算法1

**(贪心)*O(n)***

在扫描数组时维护两个值：与当前元素相邻的绝对值最大的正数乘积 pos 和负数乘积 neg。当我们枚举到 i 时：

    * 如果 nums[i]>0 ，则 nums[i]×pos 就是以 i 为终点的最大乘积；
    * 如果 nums[i]<0 ，则 nums[i]×neg 就是以 i 为终点的最大乘积；<br>
然后用 nums[i]∗pos 和 nums[i]∗neg 更新 pos 和 neg 的值。

```CPP
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int pos[size], neg[size];
        
        int res = nums[0];
        pos[0] = neg[0] = nums[0];
        
        for(int i = 1; i < size; i ++){
            pos[i] = max( max(pos[i-1]*nums[i], neg[i-1]*nums[i]), nums[i] );
            neg[i] = min( min(pos[i-1]*nums[i], neg[i-1]*nums[i]), nums[i] );
            
            res = max(pos[i], res);
        }
        
        return res;
    }
};
```