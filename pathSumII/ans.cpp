/**
 * @file ans.cpp
 * @brief
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *  [5,4,11,2],
 *  [5,8,4,5]
 * ]
 *
 * @version
 * @date 2015-06-30 10:24
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <cstddef>

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
    void helper(TreeNode* root, int sum, vector<int>& path, vector<vector<int> >& result)
    {
        if (root == NULL)
            return;

        int leftSum = sum - root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (leftSum == 0)
                result.push_back(path);
        }
        else
        {
            helper(root->left, leftSum, path, result);
            helper(root->right, leftSum, path, result);
        }

        path.pop_back();
    }

public:
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
        vector<vector<int> > result;
        if (root == NULL)
            return result;

        vector<int> path;
        helper(root, sum, path, result);
        return result;
    }
};

