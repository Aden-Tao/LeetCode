#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        heights.push_back(-1); //在数组末尾添加高度 -1, 这会使得栈中所有数字在最后出栈。
        stack<int> st;
        
        for (int i = 0; i <= n; i ++)
        {
            while (st.size() && heights[st.top()] > heights[i])
            {
                int h = heights[st.top()];
                st.pop();
                if (st.empty())
                    res = max(res, h * i);
                else
                    res = max(res, h * (i - st.top() - 1));
            }
            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec{2,1,5,6,2,3};
    assert(s.largestRectangleArea(vec) == 10);

    return 0;
}