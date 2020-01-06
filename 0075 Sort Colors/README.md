## 算法1

**(双指针法)*O(n)***

1. 设置两个index，一个代表0和1的分界线，一个代表1和2的分界线，初始时分别在两边
2. 扫描一遍数组，遇到0则swap后修改0和1的分界线，遇到1则接着遍历，遇到2则swap后修改1和2的分界线

```CPP
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, h = nums.size()-1;
        while(m <= h){
            if(nums[m] == 1)
                m ++;
            else if(nums[m] == 0){
                swap(nums[l], nums[m]);
                m ++, l ++;
            }
            else{
                swap(nums[h], nums[m]);
                h --;
            }
        }
    }
};
```