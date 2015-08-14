/**
 * @file ans.c
 * @brief
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by
 * more than 1.
 *
 * @version
 * @date 2015-06-29 15:37
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#define max(x, y) x > y ? x : y

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool getTreeHeight(struct TreeNode* root, int* height)
{
    if (root == NULL)
    {
        *height = 0;
        return true;
    }

    int leftHeight = 0;
    int rightHeight = 0;
    bool isLeftBalanced = getTreeHeight(root->left, &leftHeight);
    if (!isLeftBalanced)
        return false;
    bool isRightBalanced = getTreeHeight(root->right, &rightHeight);
    if (!isRightBalanced)
        return false;

    *height = (max(leftHeight, rightHeight)) + 1;
    return abs(leftHeight - rightHeight) <= 1;
}

bool isBalanced(struct TreeNode* root)
{
    int height = 0;
    return getTreeHeight(root, &height);
}

