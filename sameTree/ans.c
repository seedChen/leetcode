/**
 * @file ans.c
 * @brief
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
 *
 * @version
 * @date 2015-06-26 17:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL)
        return q == NULL;
    if (q == NULL)
        return p == NULL;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

