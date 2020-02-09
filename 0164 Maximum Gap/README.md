## 算法1

* 选择合适的桶大小 b 满足 $1<b≤(max−min)/(n−1)$。设 $b = \lfloor (max - min)/(n-1) \rfloor$。
* 所有 n 个元素被分为 $k = \lceil (max - min)/b \rceil$ 个桶。
* 因此第 i 个桶保存的值区间为：$\bigg [min + (i-1) * b, \space min + i*b \bigg )$（下标从 1 开始）。
* 显然很容易计算出每个元素属于哪个桶，$\lfloor (num - min)/b \rfloor$（下标从 0 开始）其中 num 是元素的值。
当所有 n 个元素都遍历过后，比较 k−1 个相邻桶找到最大间距。

比较直观的分析是，因为每一个桶内的元素差值都小于 b，而根据贪心思想，相邻两个元素差值的最大值肯定大于等于 b ,我们没有必要比较同一个 b 内的元素

```CPP
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
```

```Python
class Solution:
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0
        
        mi, mx = min(nums), max(nums)
        
        if mi == mx:
            return 0
        
        size = math.ceil((mx - mi)/(len(nums) - 1.0))
        
        bucketMin = [sys.maxsize] * (len(nums) + 1)
        bucketMax = [0] * (len(nums) + 1)
        
        for i in nums:
            idx = (i - mi) // size
            bucketMin[idx] = min(bucketMin[idx], i)
            bucketMax[idx] = max(bucketMax[idx], i)
            
        pre = bucketMax[0]
        res = 0
        
        for i in range(len(nums)):
            if bucketMin[i] == sys.maxsize:
                continue
                
            res = max(bucketMin[i] - pre, res)
            pre = bucketMax[i]
        
        return res
```