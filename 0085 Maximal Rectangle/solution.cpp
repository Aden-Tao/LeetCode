#include <bits/stdc++.h>
using namespace std;

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

int main(){
    Solution s;
    vector<vector<char>> vec = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    assert(s.maximalRectangle(vec) == 6);
    return 0;
}