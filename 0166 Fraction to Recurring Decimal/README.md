## 算法1

**(模拟)*O(n)***

先将所有负数运算转化为正数运算。
然后再算出分数的整数部分，再将精力集中在小数部分。

计算小数部分的难点在于如何判断是否是循环小数，以及找出循环节的位置。
回忆手工计算除法的过程，每次将余数乘10再除以除数，当同一个余数出现两次时，我们就找到了循环节。<br>
所以可以用一个哈希表 unordered_map<int,int> 记录所有余数所对应的商在小数点后第几位，当计算到相同的余数时，上一次余数的位置和当前位置之间的数，就是该小数的循环节。

```CPP
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)  return "0";
        string res;
        
        if(numerator<0 ^ denominator<0)  res += '-';
        
        long long int n = labs(numerator);
        long long int d = labs(denominator);
        
        res += to_string(n / d); //添加整数部分
        if(n % d == 0)
            return res;
        res += '.';
        unordered_map<int, int> mp;
        
        for(long long int r = n % d; r; r %= d){
            if(mp.count(r) > 0){
                res.insert(mp[r], 1, '(');
                res.push_back(')');
                break;
            }
            mp[r] = res.size();
            r *= 10;
            res += to_string(r/d);
        }
        return res;
    }
};
```