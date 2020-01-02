## 算法1

**(模拟)*O(nm)***

1. 定义四个方向常数；
2. 模拟走，到头对应行或者列减一；


```CPP
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;

        while(u <= d && l <= r){
            for(int i = l; i <= r; i ++){ //to right
                res.push_back(matrix[u][i]);
            }
            u ++;
            
            for(int i = u; i <= d; i ++){ //to down
                res.push_back(matrix[i][r]);
            }
            r --;
            
            for(int i = r; i >= l && u <= d; i --){ // to left
                res.push_back(matrix[d][i]);
            }
            d --;
            
            for(int i = d; i >= u && l <= r; i --){ //to upper
                res.push_back(matrix[i][l]);
            }
            l ++;
        }
        
        return res;
    }
};
```