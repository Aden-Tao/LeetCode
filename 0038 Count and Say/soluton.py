#! python3
import itertools

class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = '1'
        for _ in range(n - 1):
            s = ''.join(str(len(list(group))) + digit
                    for digit, group in itertools.groupby(s))
        return s

if __name__ == "__main__":
    print(Solution().countAndSay(4))