#! python3
import math
import sys

class Solution:
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0
        
        mi, mx = min(nums), max(nums)
        
        if mi == mx:
            return 0
        
        size = math.ceil((mx - mi)/(len(nums) - 1.0))
        
        bucketMin = [sys.maxsize] * (len(nums) + 1)
        bucketMax = [0] * (len(nums) + 1)
        
        for i in nums:
            idx = int((i - mi) // size)
            bucketMin[idx] = min(bucketMin[idx], i)
            bucketMax[idx] = max(bucketMax[idx], i)
            
        pre = bucketMax[0]
        res = 0
        
        for i in range(len(nums)):
            if bucketMin[i] == sys.maxsize:
                continue
                
            res = max(bucketMin[i] - pre, res)
            pre = bucketMax[i]
        
        return res

if __name__ == "__main__":
    print(Solution().maximumGap([3,6,9,1]))