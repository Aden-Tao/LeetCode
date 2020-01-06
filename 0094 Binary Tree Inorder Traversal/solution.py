#! python3

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # Recursive
        res = []
        self.helper(root, res)
        return res
        
    def helper(self, root, res):
        if not root: return ;
        self.helper(root.left, res)
        res.append(root.val)
        self.helper(root.right, res)

if __name__ == "__main__":
    root, node2, node3= TreeNode(1), TreeNode(2), TreeNode(3)
    root.right, node2.left = node2, node3

    print(Solution().inorderTraversal(root))