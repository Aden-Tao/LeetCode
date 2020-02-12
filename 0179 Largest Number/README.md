## 算法1 

**(排序)*O(nlogn)***

1. 考虑简单的情况，如果只给了两个数字，那么只需要比较两个数字前后的拼接，即可确定顺序;
2. 扩展到多个数字时，存在偏序关系，即当满足AB>BA && BC>CB时，AC>CA一定成立;
3. 所以可以借助这个偏序关系直接对所有数字按照两个数字的情况进行排序;
4. 注意最后需要去除前导0;

```CPP
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> S;
        for(int i: nums)
            S.push_back(to_string(i));
        sort(S.begin(), S.end(), [](string &a, string &b){ return a + b > b + a; });
        string res;
        
        for(string s:S)
            res += s;
        
        // to exclude [0, 0] 
        while(res[0] == '0' && res.length() > 1)
            res.erase(0, 1);
        
        return res;
    }
};
```