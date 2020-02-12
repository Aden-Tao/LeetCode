## 算法1

**(数组翻转)*O(n)***

k 可能非常大，超出数组长度，所以我们要先将 k 对数组长度取模。
然后可以将数组的旋转操作分解为三次翻转操作：

1. 将整个数组翻转；
2. 将前k个数翻转；
3. 将后 n−k 个数翻转，其中 n 是数组长度；

```CPP
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```