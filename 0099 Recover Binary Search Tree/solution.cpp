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
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second, *prep = NULL;
        while (root)
        {
            if (!root->left)
            {
                if (prep && prep->val > root->val)
                {
                    if (!first) first = prep, second = root;
                    else second = root;
                }
                prep = root;
                root = root->right;
            }
            else
            {
                TreeNode *p = root->left;
                while (p->right && p->right != root) p = p->right;
                if (!p->right)
                {
                    p->right = root;
                    root = root->left;
                }
                else
                {
                    p->right = NULL;
                    if (prep && prep->val > root->val)
                    {
                        if (!first) first = prep, second = root;
                        else second = root;
                    }
                    prep = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};

void print_bfs(TreeNode* p)
{
    if (!p) return;
    std::vector<std::string> v;
    std::queue<TreeNode *> q;
    q.push(p);
    do {
        TreeNode *node = q.front(); q.pop();
        if (node)
            v.push_back(std::to_string(node->val));
        else {
            v.push_back("#");
            continue;
        }
        q.push(node->left);
        q.push(node->right);
    } while (!q.empty());

    auto found = std::find_if(v.rbegin(), v.rend(), [](const std::string &s){ return s != "#"; });
    v.erase(found.base(), v.end());
    for (const auto &s : v)
        std::cout << s << ",";
    std::cout << "\b " << std::endl;
}

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);

    node3.left = &node1;
    node3.right = &node4;
    node4.left = &node2;

    Solution s;
    print_bfs(&node3);
    s.recoverTree(&node3);
    print_bfs(&node3);

    return 0;
}
