/**
 * @file ans.c
 * @brief
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * @version
 * @date 2015-06-28 12:38
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

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    if (NULL == inorder || NULL == postorder || inorderSize < 0 || postorderSize < 0 || inorderSize != postorderSize)
        return NULL;

    if (inorderSize == 0 || postorderSize == 0)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int val = postorder[postorderSize-1];
    root->val = val;

    int i = 0;
    for (; i < inorderSize; i++)
        if (inorder[i] == val)
            break;
    root->left = buildTree(inorder, i, postorder, i);
    root->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);

    return root;
}

