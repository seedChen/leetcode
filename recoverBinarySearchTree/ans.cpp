/**
 * @file ans.cpp
 * @brief
 * Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a
 * constant space solution?
 *
 * @version
 * @date 2015-06-26 11:44
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
private:
    TreeNode* pre;
    TreeNode* p[2];
    int i;

public:
    void find(TreeNode* root)
    {
        if (root)
        {
            find(root->left);

            if (pre != NULL && root->val < pre->val)
            {
                if (i == 0)
                {
                    p[i++] = pre;
                    p[i] = root;
                }
                else
                    p[i] = root;
            }

            pre = root;
            find(root->right);
        }
    }

    void recoverTree(TreeNode* root)
    {
        if (root == NULL)
            return;

        i = 0;
        pre = NULL;
        find(root);

        int tmp = p[0]->val;
        p[0]->val = p[1]->val;
        p[1]->val = tmp;
    }
};

