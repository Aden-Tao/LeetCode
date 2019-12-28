#! python3

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:    return True
        stack = []
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            else:
                if stack:
                    t = stack.pop()
                else:
                    return False
                
                if (t, c) in [('(', ')'), ('[', ']'), ('{', '}')]:
                    continue
                else:
                    return False
        
        return len(stack)==0

if __name__ == "__main__":
    print(Solution().isValid("()[]{}"))
    print(Solution().isValid("(])"))