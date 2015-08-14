/**
 * @file ans.cpp
 * @brief
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 * @version
 * @date 2015-05-28 14:39
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    void helper(vector<vector<int> >& result, vector<int>& nums, int firstIdx)
    {
        if (firstIdx == (int)nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = firstIdx; i < (int)nums.size(); ++i)
        {
            int tmp = nums[firstIdx];
            nums[firstIdx] = nums[i];
            nums[i] = tmp;
            helper(result, nums, firstIdx + 1);
            tmp = nums[firstIdx];
            nums[firstIdx] = nums[i];
            nums[i] = tmp;
        }
    }

public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> > result;
        if (nums.size() == 0)
            return result;

        helper(result, nums, 0);

        return result;
    }
};

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3};
    vector<int> nums(a, a + 3);
    Solution s;
    vector<vector<int> > result = s.permute(nums);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j << " " ;
        }
        cout << endl;
    }
    return 0;
}
