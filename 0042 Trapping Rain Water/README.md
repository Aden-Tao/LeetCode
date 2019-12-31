## 算法1

**(单调栈)*O(n)***

1. 考虑每个位置左边和右边第一个比它高的位置的矩形条，以及三个矩形条构成的U型;
2. 维护单调递减的单调栈，在每次出栈时，i即为当前栈顶st.top()位置第一个比它高的矩形的位置，弹出栈顶，并将当前栈顶记为top;
3. 假设此时栈中仍然存在矩形，现在st.top()、top与i三个位置构成一个U型，其中top位置代表U型的底部，此时可以计算出该U型所能接受的水的面积为```(i−st.top()−1)∗(min(height[st.top()],height[i])−height[top])```;

```CPP
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int res = 0;
        stack<int> s;
        for (int i = 0; i < n; i ++)
        {
            while (!s.empty() && height[s.top()] < height[i])
            {
                int t = s.top();
                s.pop();
                if (s.empty())  break;
                res += (i - s.top() - 1) * (min(height[i], height[s.top()]) - height[t]);
            }
            s.push(i);
        }
        return res;
    }
};
```
```Python
class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # use stack, if stack is empty or height[idx] <= stack.top(), push idx
        # 
        stack = []
        res, i = 0, 0
        while i < len(height):
            if len(stack) == 0 or height[stack[-1]] >= height[i]:
                stack.append(i)
                i += 1
            else:
                t = stack[-1]
                stack.pop()
                
                if len(stack) == 0:
                    continue
                    
                res += (min(height[stack[-1]], height[i]) - height[t]) * (i - stack[-1] - 1);
                
        return res
```
## 算法2

**(三次线性扫描)*O(n)***

1. 每个矩形条上方所能接受的水的高度，是由它左边最高的矩形，和右边最高的矩形决定的。具体地，假设第 i 个矩形条的高度为 ```height[i]```，且矩形条左边最高的矩形条的高度为 ```left_max[i]```，右边最高的矩形条高度为 ```right_max[i]```，则该矩形条上方能接受水的高度为 ```min(left_max[i], right_max[i]) - height[i]```;
2. 需要分别从左向右扫描求 left_max，从右向左求 right_max，最后统计答案即可;
3. 注意特判 n==0;

```CPP
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        if (n == 0)  return res;
        
        vector<int> left(n), right(n);
        left[0] = height[0];
        for (int i = 1; i < n; i ++)
            left[i] = max(left[i - 1], height[i]);
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i --)
            right[i] = max(right[i + 1], height[i]);
        
        for (int i = 0; i < n; i ++)
            res += min(left[i], right[i]) - height[i];
        return res;
    }
};
```