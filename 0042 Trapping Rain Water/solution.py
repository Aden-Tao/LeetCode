#! python3

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
                    
                res += (min(height[stack[-1]], height[i]) - height[t]) * (i - stack[-1] - 1)
                
        return res

if __name__ == "__main__":
    print(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]))