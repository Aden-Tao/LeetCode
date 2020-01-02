#! python3
import math

class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        return self.helper([x+1 for x in range(n)], n, k-1);
    
    def helper(self, nums, n, k):
        if n==1:
            return str(nums[0])
        
        idx = k // math.factorial(n-1)
        return str(nums[idx]) + self.helper(nums[:idx] + nums[idx+1:], n-1, k % math.factorial(n-1))
        
if __name__ == "__main__":
    print(Solution().getPermutation(3,3))