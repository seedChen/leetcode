/**
 * @file ans.cpp
 * @brief
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 * @version
 * @date 2015-06-29 15:08
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    ListNode* curr;

    TreeNode* helper(int size)
    {
        if (size <= 0)
            return NULL;

        TreeNode* left = helper(size / 2);
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;
        TreeNode* right = helper(size - 1 - size / 2);

        root->left = left;
        root->right = right;
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head == NULL)
            return NULL;

        int len = 0;
        curr = head;
        ListNode* p = head;
        while(p)
        {
            len++;
            p = p->next;
        }

        return helper(len);
    }
};

