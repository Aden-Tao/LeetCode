## 算法1

**(递归生成合法括号序列)*O($C^{n}_{2n}$)***

1. 使用递归；
2. 放置左括号的条件是当前左括号数目不超过*n*；
3. 放置右括号的条件是当前右括号的数目不超过左括号的数目;
   
   时间复杂度就是答案个数，也就是经典的[卡特兰数](https://baike.baidu.com/item/%E5%8D%A1%E7%89%B9%E5%85%B0%E6%95%B0)

```CPP
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", n, n, res);
        return res;
    }
    
    void dfs(string s, int left, int right, vector<string> &res){
        if(left > right)  return ;
        if(left == 0 && right == 0)
            res.push_back(s);
        if(left > 0)
            dfs(s+'(', left - 1, right, res);
        if(right > 0)
            dfs(s+')', left, right - 1, res);
    }
};
```