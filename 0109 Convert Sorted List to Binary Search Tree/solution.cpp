#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (!head)  return NULL;
        if (!head->next)  return new TreeNode(head->val);
        
        ListNode *fast = head, *slow = head, *pre;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;  //break
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    } 
};

ListNode *createLinkedList(vector<int>::iterator beg, vector<int>::iterator end)
{
    ListNode *head = beg == end ? NULL : new ListNode(*beg ++);
    for (ListNode *cur = head; beg != end; cur = cur->next)
        cur->next = new ListNode(*beg++);
    return head;
}

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
    ListNode *head = createLinkedList(nums.begin(), nums.end());
    TreeNode* root = Solution().sortedListToBST(head);
    preOrderPrint(root);
	return 0;
}