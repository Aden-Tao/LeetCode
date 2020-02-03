## 算法1

**(递归)*O(n)***

递归建立整棵二叉树。
每次以中点为根，以左半部分为左子树，右半部分为右子树。先分别递归建立左子树和右子树，然后令根节点的指针分别指向两棵子树

证明：
我们证明一个更强的结论，该算法得到的BST满足：任意节点的左右子树的所有高度的差不大于1（注意不是最大高度）。
在每一次递归过程中，左半部分的长度最多比右半部分的长度少1，那会不会有这种情况：左半部分的高度分别有 *m−1,m*右半部分的高度有 *m,m+1*，则当前节点的高度就是 *m,m+1,m+2*,（要加上当前根节点这一层，所以都要加1），则此时树的高度差为2，不平衡。<br>
实际上这种情况是不可能的：**反证**，对于左子树，由于存在高度 *m−1*，所以左半部分最多有 *$2^m$ - 2*个数；对于右子树，由于存在高度 *m* 和 *m+1*，所以右半部分最少有 $2^m$ 个数，此时左右两部分的数的个数最少差2，矛盾。

```CPP
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())  return NULL;
        return build(nums, 0, nums.size() - 1);
    }
    
    TreeNode* build (vector<int> &nums, int l, int r)
    {
        if (l > r)  return NULL;
        int mid = l + r >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);
        return root;
    }
};
```