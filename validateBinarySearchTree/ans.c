/**
 * @file ans.c
 * @brief
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's
 * key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * @version
 * @date 2015-06-26 11:41
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* pre = NULL;

bool isValidBST(struct TreeNode* root)
{
    if (root)
    {
        if (!isValidBST(root->left))
            return false;

        if (pre != NULL && root->val <= pre->val)
            return false;

        pre = root;
        return isValidBST(root->right);
    }

    return true;
}

int main(int argc, char *argv[])
{
    struct TreeNode n2 = {1, NULL, NULL};
    // struct TreeNode n1 = {1, &n2, NULL};

    printf("%d\n", isValidBST(&n2));

    return 0;
}

