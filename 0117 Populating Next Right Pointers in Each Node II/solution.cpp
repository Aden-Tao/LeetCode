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
        while (cur)
        {
            Node* dummy = new Node(0);
            Node* p = dummy;
            while (cur)
            {
                if (cur -> left)
                {
                    p -> next = cur -> left;
                    p = p -> next;
                }
                if (cur -> right)
                {
                    p -> next = cur -> right;
                    p = p -> next;
                }
                cur = cur -> next;
            }
            p -> next = NULL;
            cur = dummy -> next;
        }
        return root;
    }
};

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
    Node root(1);
    Node t2(2);
    Node t3(3);
    Node t4(4);
    Node t5(5);
    Node t7(7);
	
    root.left = &t2;
    root.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.right = &t7;
    
	Solution s;
	s.connect(&root);
	print(&root);
    
  return 0;
}