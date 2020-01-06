## 算法1

**(公式)*O(1)***

使用公式 ```Gray(i) = i ^ (i/2)```

```CPP
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0; i< 1<<n; i++)
            res.push_back(i ^ i>>1);
        return res;
    }
};
```
## 算法2

**(回溯)*O($2^{n}$)***


```CPP
class Solution {
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> res;
        helper(bits, res, n);
        return res;
    }
    
    void helper(bitset<32> &bits, vector<int> & res, int k){
        if(k == 0)
            res.push_back(bits.to_ulong());
        else{
            helper(bits, res, k-1);
            bits.flip(k - 1);
            helper(bits, res, k-1);
        }
    }
};
```