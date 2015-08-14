/**
 * @file ans.c
 * @brief
 * Given an array where elements are sorted in ascending order, convert it to
 * a height balanced BST.
 *
 * @version
 * @date 2015-06-29 10:52
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

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (numsSize <= 0 || nums == NULL)
        return NULL;

    int mid = numsSize / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);

    return root;
}

