/**
 * @file ans.cpp
 * @brief
 * Given an array S of n integers, are there elements a, b, c in S such that
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order.
 * (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *         A solution set is:
 *             (-1, 0, 1)
 *             (-1, -1, 2)
 *
 * @version
 * @date 2015-05-07 16:44
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > ret;
        if (nums.size() < 3)
            return ret;

        sort(nums.begin(), nums.end(), less<int>());

        int i, j, k;
        int target;
        for (i = 0; i < nums.size() - 2; )
        {
            target = 0 - nums[i];
            j = i + 1;
            k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] < target)
                {
                    while (nums[j] == nums[j + 1] && j < k - 1) j++;
                    j++;
                }
                else if (nums[j] + nums[k] > target)
                {
                    while (nums[k] == nums[k - 1] && j < k - 1) k--;
                    k--;
                }
                else
                {
                    vector<int> item;
                    item.push_back(nums[i]);
                    item.push_back(nums[j]);
                    item.push_back(nums[k]);
                    ret.push_back(item);
                    while (nums[j] == nums[j + 1] && j < k - 1) j++;
                    j++;
                }
            }
            while (nums[i] == nums[i + 1] && i < nums.size() - 3) i++;
            i++;
        }
        return ret;
    }
};
