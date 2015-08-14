/**
 * @file ans.c
 * @brief
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 * @version
 * @date 2015-06-30 10:04
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum)
{
    if (root == NULL)
        return false;

    int leftSum = sum - root->val;
    if (root->left == NULL && root->right == NULL)
        return leftSum == 0;
    else
        return hasPathSum(root->left, leftSum) || hasPathSum(root->right, leftSum);
}

