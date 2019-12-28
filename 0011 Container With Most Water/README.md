## 算法1

**(双指针)O(n)**

用两个指针*i,  j*,分别指向头和尾，如果$a_{i}$ > $a_{j}$，则 *j --*,否则 *i ++*，知道 *i = j*为止，每次迭代都更新最大值.

```CPP
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; )
        {
            res = max(res, 
                min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) j -- ;
            else i ++ ;
        }
        return res;
    }
};
```