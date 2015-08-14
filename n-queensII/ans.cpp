/**
 * @file ans.cpp
 * @brief
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of
 * distinct solutions.
 *
 * @version
 * @date 2015-05-31 16:31
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
    int totalNQueens(int n)
    {
        int result = 0;;
        if (n == 1)
        {
            return 1;
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

            result++;
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
    int ret = s.totalNQueens(4);
    cout << ret << endl;

    return 0;
}

