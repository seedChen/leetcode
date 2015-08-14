/**
 * @file ans.cpp
 * @brief
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 *
 * @version
 * @date 2015-05-29 10:21
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
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
    vector<vector<int> > permuteUnique(vector<int>& nums)
    {
        vector<vector<int> > ret;
        if (nums.size() == 0)
            return ret;

        sort(nums.begin(), nums.end());
        ret.push_back(nums);
        while(nextPermutation(nums))
        {
            ret.push_back(nums);
        }

        return ret;
    }
};

