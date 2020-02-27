#! python3

class Solution:
    def isHappy(self, n):
        slow = self.helper(n)
        fast = self.helper(slow)
        
        while slow != fast :
            slow = self.helper(slow)
            fast = self.helper(self.helper(fast))
        
        if slow == 1:
            return True
        else:
            return False

    def helper(self, n):
        r = 0
        while n:
            r += (n % 10) ** 2
            n //= 10
        
        return r
    
if __name__ == "__main__":
    print(Solution().isHappy(19))
    print(Solution().isHappy(22))