#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

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

void preOrderPrint(TreeNode* root)
{
    if (!root)  cout << "# ";  
    else
    {
        cout << root->val << " ";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }       
}

int main() {
    vector<int> nums{-10,-3,0,5,9};
    TreeNode* root = Solution().sortedArrayToBST(nums);
    preOrderPrint(root);
	return 0;
}