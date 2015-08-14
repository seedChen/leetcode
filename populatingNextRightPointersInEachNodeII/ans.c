/**
 * @file ans->c
 * @brief
 * Follow up for problem "Populating Next Right Pointers in Each Node"->
 *
 * What if the given tree could be any binary tree? Would your previous
 * solution still work?
 *
 * Note:
 *
 * You may only use constant extra space->
 * For example,
 * Given the following binary tree,
 *          1
 *         /  \
 *        2    3
 *       / \    \
 *      4   5    7
 * After calling your function, the tree should look like:
 *         1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 *
 * @version
 * @date 2015-07-01 11:30
 * @author chen_juntao
 * @email chen_juntao@outlook->com
 */

#include <cstddef>

struct TreeLinkNode
{
 int val;
 struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root)
{
    struct TreeLinkNode* head = root; //The left most node in the lower level
    struct TreeLinkNode* prev = NULL; //The previous node in the lower level
    struct TreeLinkNode* curr = NULL; //The current node in the upper level
    while (head != NULL)
    {
        curr = head;
        prev = NULL;
        head = NULL;
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                if (prev != NULL)
                    prev->next = curr->left;
                else
                    head = curr->left;
                prev = curr->left;
            }

            if (curr->right != NULL)
            {
                if (prev != NULL)
                    prev->next = curr->right;
                else
                    head = curr->right;
                prev = curr->right;
            }
            curr = curr->next;
        }
    }
}

