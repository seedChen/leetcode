/**
 * @file ans.c
 * @brief
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *          1
 *           \
 *            2
 *             \
 *              3
 *               \
 *                4
 *                 \
 *                  5
 *                   \
 *                    6
 *
 * @version
 * @date 2015-06-30 10:46
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

void flatten(struct TreeNode* root)
{
    struct TreeNode* curr = root;
    while(curr)
    {
        if (curr->left)
        {
            struct TreeNode* pre = curr->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

