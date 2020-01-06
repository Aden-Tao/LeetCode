## 算法1

**(单调栈)*O(n)***

1. 找到每个柱形条左边和右边最近的比自己低的矩形条，然后用宽度乘上当前柱形条的高度作为备选答案;
2. 经典做法是单调栈，维护一个单调递增的栈，如果当前柱形条```i```的高度比栈顶要低，则栈顶元素```cur```出栈。出栈后，```cur```右边第一个比它低的柱形条就是```i```，左边第一个比它低的柱形条是当前栈中的```top```。不断出栈直到栈为空或者柱形条```i```不再比```top```低;
3. 满足2之后，当前矩形条i进栈;

```CPP
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
```