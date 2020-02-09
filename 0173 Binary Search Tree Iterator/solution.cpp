#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* p = s.top();
        s.pop();
        int val = p->val;
        p = p->right;
        while (p)
        {
            s.push(p);
            p = p->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

int main(){
    TreeNode *root = new TreeNode(7);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n6 = new TreeNode(9);
    TreeNode *n7 = new TreeNode(20);

    root -> left = n2;
    root -> right = n3;
    n3 -> left = n6;
    n3 -> right = n7;

    BSTIterator *iterator = new BSTIterator(root);
    cout << (*iterator).next() << endl;    // 返回 3
    cout << (*iterator).next() << endl;    // 返回 7
    cout << (*iterator).hasNext() << endl; // 返回 true
    cout << (*iterator).next() << endl;    // 返回 9
    cout << (*iterator).hasNext()  << endl; // 返回 true
    cout << (*iterator).next() << endl;    // 返回 15
    cout << (*iterator).hasNext() << endl; // 返回 true
    cout << (*iterator).next() << endl;    // 返回 20
    cout << (*iterator).hasNext(); // 返回 false

    return 0;
}
