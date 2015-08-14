/**
 * @file ans.cpp
 * @brief
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 *
 * @version
 * @date 2015-05-30 18:41
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
private:
    void reverse(vector<int>& nums, int startIdx)
    {
        int i = startIdx;
        int j = nums.size() - 1;
        while (i < j)
        {
            nums[i] = nums[i] + nums[j];
            nums[j] = nums[i] - nums[j];
            nums[i] = nums[i] - nums[j];
            i++;
            j--;
        }
    }

    bool nextPermutation(vector<int>& nums)
    {
        int numsSize = nums.size();

        int i, j;
        for (i = numsSize - 2; i != -1; i--)
        {
            if (nums[i] < nums[i + 1])
                break;
        }

        if (i != -1)
        {
            for (j = numsSize - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                    break;
            }
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;

            reverse(nums, i + 1);
            return true;
        }
        else
            return false;
    }

public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > result;
        if (n == 1)
        {
            string tmp("Q");
            vector<string> tmp2;
            tmp2.push_back(tmp);
            result.push_back(tmp2);
            return result;
        }
        if (n < 4)
            return result;

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            ans.push_back(i);

        do
        {
            vector<string> vs;
            for (int i = 0; i < n - 1; ++i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (abs(ans[i] - ans[j]) == j - i)
                        goto NEXT;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                string s(n, '.');
                s[ans[i]] = 'Q';
                vs.push_back(s);
            }
            result.push_back(vs);
NEXT:
            continue;
        }
        while (nextPermutation(ans));

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<string> > ret = s.solveNQueens(4);
    for (auto i : ret)
    {
        for (auto j : i)
        {
            cout << j << endl;
        }
        cout << endl;
    }

    return 0;
}

