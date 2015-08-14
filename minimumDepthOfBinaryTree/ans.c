/**
 * @file ans.c
 * @brief
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * @version
 * @date 2015-06-30 09:42
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdlib.h>

#define min(x, y) x < y ? x : y

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->left && root->right)
    {
        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);
        return (min(leftHeight, rightHeight)) + 1;
    }
    else if (root->left)
    {
        return minDepth(root->left) + 1;
    }
    else
    {
        return minDepth(root->right) + 1;
    }
}

