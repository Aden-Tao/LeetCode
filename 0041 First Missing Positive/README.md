## 算法1

**(桶排序)*O(n)***

1. 不用额外空间的桶排序：保证1出现在nums[0]的位置上，2出现在nums[1]的位置上，…，n出现在nums[n-1]的位置上，其他的数字不管。例如[3,4,-1,1]将被排序为[1,-1,3,4]
2. 遍历nums，找到第一个不在应在位置上的1到n的数。例如，排序后的[1,-1,3,4]中第一个 nums[i] != i + 1 的是数字2（注意此时i=1）

```CPP
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; i ++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};
```

```Java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        
        for(int i = 0; i < len; i++){
            while(nums[i] > 0 && nums[i] < len + 1 && nums[i] != nums[nums[i] - 1]){
                swap(nums, i, nums[i] - 1);
            }
        }
        
        for(int i = 0; i < len; i++)
            if(nums[i] != i+1)
                return i + 1;
        
        return len + 1;
    }
    
    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```