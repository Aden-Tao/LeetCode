## 算法1

**(计数)*O($n^{2}$)***

1. 从高位到低位依次考虑；
2. 对于每一位，从小到大依次枚举未使用过的数，确定当前位置是第几位；

```CPP
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        for (int i = 1; i <= n; i ++) num.push_back(i);
        
        vector<int> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i ++)  fact[i] = i * fact[i - 1];
        
        k --;
        string res = "";
        for (int i = n; i > 0; i --)
        {
            int idx = k / fact[i - 1];
            k = k % fact[i - 1];
            res.push_back(num[idx] + '0');
            num.erase(num.begin() + idx);
        }
        return res;
    }
};
```
```Python
class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        return self.helper([x+1 for x in range(n)], n, k-1);
    
    def helper(self, nums, n, k):
        if n==1:
            return str(nums[0])
        
        idx = k // math.factorial(n-1)
        return str(nums[idx]) + self.helper(nums[:idx] + nums[idx+1:], n-1, k % math.factorial(n-1))
        
```