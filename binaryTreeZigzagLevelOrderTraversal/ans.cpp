/**
 * @file ans.cpp
 * @brief
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *  /  \
 * 15   7
 * return its zigzag level order traversal as:
 * [
 *  [3],
 *  [20,9],
 *  [15,7]
 * ]
 *
 * @version
 * @date 2015-06-27 16:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int> > result;
        if (!root)
            return result;

        bool left2right = true;
        deque<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty())
        {
            int n = queue.size();
            vector<int> level;
            for (int i = 0; i < n; i++)
            {
                TreeNode* p = queue.front();
                queue.pop_front();
                level.push_back(p->val);
                if (p->left)
                    queue.push_back(p->left);
                if (p->right)
                    queue.push_back(p->right);
            }

            if (!left2right)
                reverse(level.begin(), level.end());
            result.push_back(level);
            left2right = !left2right;
        }

        return result;
    }
};

