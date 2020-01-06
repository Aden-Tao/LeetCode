## 算法1

**(单调栈)*O(nm)***

1. 将 [Largest Rectangle in Histogram](../0084&#32;Largest&#32;Rectangle&#32;in&#32;Histogram/README.md) 问题扩展到二维。
2. 一行一行考虑，类比 上一题，一行内所有柱形条的高度 heights 就是当前 (i,j) 位置能往上延伸的最大高度。
3. 直接套用 Largest Rectangle in Histogram 的单调栈算法即可。

```CPP
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0)  return 0;
        int m = matrix[0].size();
        int res = 0;
        
        vector<int> heights(m + 1, 0);
        heights[m] = -1;
        
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j ++)
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] ++;
            
            stack<int> st;
            for (int j = 0; j <= m; j ++)
            {
                while (st.size() && heights[st.top()] > heights[j])
                {
                    int h = heights[st.top()];
                    st.pop();
                    if (st.empty())
                        res = max(res, h * j);
                    else
                        res = max(res, h * (j - st.top() - 1));
                }
                st.push(j);
            }
        }
        return res;
    }
};
```