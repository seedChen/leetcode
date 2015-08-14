/**
 * @file ans.cpp
 * @brief
 * Given a sorted array of integers, find the starting and ending position of a
 * given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 * @version
 * @date 2015-05-20 10:41
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

class Solution
{
private:
    int findFirstTarget(vector<int>& nums, int target, int start, int end)
    {
        if (start > end)
            return -1;

        int m = (start + end) / 2;

        if (nums[m] < target)
        {
            start = m + 1;
        }
        else if (nums[m] > target)
        {
            end = m - 1;
        }
        else
        {
            if ((m > 0 && nums[m - 1] != target) || m == 0)
                return m;
            else
                end = m - 1;
        }

        return findFirstTarget(nums, target, start, end);
    }

    int findLastTarget(vector<int>& nums, int target, int start, int end)
    {
        if (start > end)
            return -1;

        int m = (start + end) / 2;

        if (nums[m] < target)
        {
            start = m + 1;
        }
        else if (nums[m] > target)
        {
            end = m - 1;
        }
        else
        {
            if ((m < (int)nums.size() - 1 && nums[m + 1] != target) || m == (int)nums.size() - 1)
                return m;
            else
                start = m + 1;
        }

        return findLastTarget(nums, target, start, end);
    }

public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result;
        if (nums.size() == 0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int first = findFirstTarget(nums, target, 0, nums.size() - 1);
        int last = findLastTarget(nums, target, 0, nums.size() - 1);

        result.push_back(first);
        result.push_back(last);

        return result;
    }
};

