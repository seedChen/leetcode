/**
 * @file ans.c
 * @brief
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 *
 * @version
 * @date 2015-06-27 16:42
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#define max(x, y) x > y ? x : y

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
    if (!root)
        return 0;

    int leftDep = maxDepth(root->left);
    int rightDep = maxDepth(root->right);

    return (max(leftDep, rightDep)) + 1;
}

