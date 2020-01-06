#! python3

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if(n == 0):    return []
        
        return self.dfs(1, n)
    
    def dfs(self, s, e):
        if s > e:
            return [None]
        
        res = []
        for cur_root in range(s, e + 1):
            left = self.dfs(s, cur_root - 1)
            right = self.dfs(cur_root + 1, e)
            
            for l in left:
                for r in right:
                    root = TreeNode(cur_root)
                    root.left = l
                    root.right= r
                    res.append(root)
        return res

def print_bfs(p):
    if not p:  return
    res, q = [], []
    q.append(p)
    while len(q):
        node = q[0]
        q.pop(0)
        if node:
            res.append(str(node.val))
        else:
            res.append('#')
            continue
        q.append(node.left)
        q.append(node.right)
    for _ in res[::-1]:
        if _ == '#':
            res.pop()
        else:
            break
    print(','.join(res))


if __name__ == "__main__":
    for p in Solution().generateTrees(3):
        print_bfs(p)
