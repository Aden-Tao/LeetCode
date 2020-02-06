#include "bits/stdc++.h"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node *p = head;
        while (p)
        {
            Node * tmp = new Node(p -> val);
            tmp -> next = p -> next;
            p -> next = tmp;
            p = tmp -> next;
        }
        p = head;
        while (p)
        {
            p -> next -> random = p -> random ? p -> random -> next : NULL;
            p = p -> next -> next;
        }
        p = head;
        Node *clone = p -> next, *tmp;
        while (p)
        {
            tmp = p -> next;
            p -> next = tmp -> next;
            tmp -> next = tmp -> next ? tmp -> next -> next : NULL;
            p = p -> next;
        }
        return clone;
    }
};

void print_randomlist(Node *head)
{
    while (head) {
        cout << head -> val << " ";
        if (head -> random) cout << head -> random -> val << " ";
        else cout << "NULL" << " ";
        head = head -> next;
    }
    cout << endl;
}

void clear(Node *head)
{
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{
    Solution s;
    Node head(0);
    Node node(1);
    Node last(2);

    head.next = &node;
    node.next = &last;

    head.random = &last;
    node.random = &head;
    last.random = &last;

    print_randomlist(&head);
    Node *new_head = s.copyRandomList(&head);
    print_randomlist(new_head);
    clear(new_head);

    return 0;
}