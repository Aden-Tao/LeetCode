#!python3

class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        
        for row in range(0, numRows):
            cur = [None for _ in range(row+1)]
            cur[0] = cur[-1] = 1
            
            for j in range(1, len(cur)-1):
                cur[j] = res[row-1][j-1] + res[row-1][j]
                
            res.append(cur)
            
        return res

if __name__ == "__main__":
    print(Solution().generate(5))