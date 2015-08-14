/**
 * @file ans.c
 * @brief
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * @version
 * @date 2015-06-27 17:12
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (NULL == preorder || NULL == inorder || preorderSize != inorderSize
            || preorderSize < 0 || inorderSize < 0)
        return NULL;

    if (preorderSize == 0 || inorderSize == 0)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int val = preorder[0];
    root->val = val;

    int i;
    for (i = 0; i < inorderSize; i++)
    {
        if (inorder[i] == val)
            break;
    }

    root->left = buildTree(preorder + 1, i, inorder, i );
    root->right = buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, inorderSize - i - 1);

    return root;
}

