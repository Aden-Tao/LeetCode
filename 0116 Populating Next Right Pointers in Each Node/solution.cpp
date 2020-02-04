#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return NULL;
        Node* cur = root;
        while(cur -> left)
        {
            for (Node* p = cur; p ; p = p -> next)
            {
                p -> left -> next = p -> right;
                if (p -> next)
                    p -> right -> next = p -> next -> left;
            }
            cur = cur -> left;
        }
        return root;
    }
};

using vecIter = vector<int>::iterator;
Node *createBinaryTree(vecIter beg, vecIter end)
{
    vector<Node *> vec;
    for (vecIter it = beg; it != end; ++it)
        vec.push_back(new Node(*it));
  
    for (int i = 0, pos = 0; pos != vec.size()-1; ++i)
    {
        vec[i]->left = vec[++pos];
        vec[i]->right = vec[++pos];
    }

    return *vec.begin();
}   

void print(Node *root)
{
    while (root)
    {
        cout << root->val;
        Node *cur = root->next;
        while (cur)
        {
            cout << "->" << cur->val;
            cur = cur->next;
        }
        cout << endl;
        root = root->left;
    }
}

int main(int argc, char** argv)
{
    vector<int> vec = {1,2,3,4,5,6,7};
    Node *root = createBinaryTree(vec.begin(), vec.end());
	
	Solution s;
	s.connect(root);
	print(root);
    
  return 0;
}
