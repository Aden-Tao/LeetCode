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
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if (!root)  return res;
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* p, int s)
    {
        if (!p)  return ;
        s = s * 10 + p -> val;
        if (p -> left)  dfs(p -> left, s);
        if (p -> right) dfs(p -> right, s);
        if (!p -> left && !p -> right)
            res += s;
        return;
    }
};

int main(){
    TreeNode root(1);
    TreeNode t2(2);
    TreeNode t3(3);

    root.left = &t2;
    root.right = &t3;

    cout << Solution().sumNumbers(&root) << endl;
    return 0;
}