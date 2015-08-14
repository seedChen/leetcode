/**
 * @file ans.c
 * @brief
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 * @version
 * @date 2015-06-26 17:19
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool helper(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL)
        return q == NULL;
    if (q == NULL)
        return p == NULL;

    if (p->val == q->val)
        return helper(p->left, q->right) && helper(p->right, q->left);
    else
        return false;
}

bool isSymmetric(struct TreeNode* root)
{
    if (NULL == root)
        return true;

    return helper(root->left, root->right);
}

