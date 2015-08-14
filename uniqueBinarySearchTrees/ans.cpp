/**
 * @file ans.cpp
 * @brief
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *     1         3     3      2      1
 *      \       /     /      / \      \
 *       3     2     1      1   3      2
 *      /     /       \                 \
 *     2     1         2                 3
 *
 * @version
 * @date 2015-06-24 20:31
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 0)
            return 0;

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i / 2; j++)
                dp[i] = dp[i] + dp[j] * dp[i-j-1];

            dp[i] = i & 1 ? dp[i] * 2 + dp[i/2] * dp[i/2] : dp[i] * 2;
        }

        return dp[n];
    }
};

