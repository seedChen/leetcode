/**
 * @file ans.cpp
 * @brief
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *
 *     1
 *      \
 *       2
 *      /
 *     3
 *
 *
 *
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 *
 * @version
 * @date 2015-06-24 16:00
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
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (!root)
            return result;

        vector<TreeNode*> stack;
        stack.push_back(root);

        while (!stack.empty())
        {
            while (stack.back()->left)
                stack.push_back(stack.back()->left);

            while (true && !stack.empty())
            {
                TreeNode* p = stack.back();
                stack.pop_back();
                result.push_back(p->val);

                if (p->right)
                {
                    stack.push_back(p->right);
                    break;
                }
            }
        }

        return result;
    }
};

