/**
 * @file ans.cpp
 * @brief
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *         1
 *        / \
 *       2   3
 *
 *
 *
 * Return 6.
 *
 *
 * @version
 * @date 2015-08-11 22:28
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <cstddef>
#include <map>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    int result;

    int postOrder(TreeNode* root)
    {
        if (NULL == root)
            return 0;

        int l = postOrder(root->left);
        int r = postOrder(root->right);

        int ret = max(max(l + root->val, r + root->val), root->val);
        result = max(max(result, ret), l + root->val + r);

        return ret;
    }

public:
    int maxPathSum(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        result = INT_MIN;
        postOrder(root);
        return result;;
    }
};

