## 算法1

**(线性素数筛选)*O(n)***

厄拉多塞筛法：

要得到自然数n以内的全部质数，必须把不大于根号n的所有质数的倍数剔除，剩下的就是质数。

```CPP
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, false);
        int cnt = 0;
        
        for(int i = 2; i < n; i++){
            if(prime[i] == false) 
                cnt++;
            for(int j = 2; j*i < n; j++)
                prime[j*i] = true;
    }
        return cnt;
    }
};
```