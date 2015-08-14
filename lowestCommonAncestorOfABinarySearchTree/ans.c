/**
 * @file ans.c
 * @brief
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______6______
 *        /              \
 *      _2__          ___8__
 *    /      \        /      \
 *   0      _4       7       9
 *         /  \
 *        3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
 * Another example is LCA of nodes 2 and 4 is 2, since a node can be
 * a descendant of itself according to the LCA definition.)
 *
 * @version
 * @date 2015-08-12 16:11
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

struct TreeNode* helper(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (p->val < root->val && q->val < root->val)
        return helper(root->left, p, q);

    if (p->val > root->val && q->val > root->val)
        return helper(root->right, p, q);

    return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (NULL == root || NULL == p || NULL == q)
        return NULL;

    return helper(root, p, q);
}

