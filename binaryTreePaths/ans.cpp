/**
 * @file ans.cpp
 * @brief
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 *
 *
 *
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 *
 * @version
 * @date 2015-08-17 15:50
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<string> result;

    void helper(TreeNode* root, vector<int>& path)
    {
        path.push_back(root->val);
        if (root->left)
        {
            helper(root->left, path);
        }
        if (root->right)
        {
            helper(root->right, path);
        }
        if (root->left == NULL && root->right == NULL)
        {
            string ret = to_string(path[0]);
            for (int i = 1; i < path.size(); i++)
            {
                ret = ret + "->" + to_string(path[i]);
            }
            result.push_back(ret);
        }
        path.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (NULL == root)
            return result;
        vector<int> path;
        helper(root, path);
        return result;
    }
};

