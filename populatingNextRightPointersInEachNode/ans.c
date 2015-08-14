/**
 * @file ans.c
 * @brief
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous
 * solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *         /  \
 *        2    3
 *       / \    \
 *      4   5    7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *         /  \
 *        2 -> 3 -> NULL
 *       / \    \
 *      4-> 5 -> 7 -> NULL
 *
 * @version
 * @date 2015-07-01 10:45
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include  <cstddef>

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root)
{
    if (!root) return;

    struct TreeLinkNode* pre = root;
    struct TreeLinkNode* cur = NULL;

    while (pre->left)
    {
        cur = pre;
        while (cur)
        {
            cur->left->next = cur->right;
            if (cur->next)
                cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}

