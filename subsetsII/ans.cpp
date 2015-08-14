/**
 * @file ans.cpp
 * @brief
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 * @version
 * @date 2015-06-12 17:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    void helper(const vector<int>& numbers, vector<int>& path, int start,  vector<vector<int> >& result)
    {
        result.push_back(path);

        int i = start;
        while (i < (int)numbers.size())
        {
            path.push_back(numbers[i]);
            helper(numbers, path, i + 1, result);
            path.pop_back();

            while(i + 1 < (int)numbers.size() && numbers[i] == numbers[i+1])i++;
            i++;
        }
    }

public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> > result;
        if (nums.size() == 0)
            return result;

        sort(nums.begin(), nums.end());

        vector<int> path;
        path.reserve(nums.size());

        helper(nums, path, 0, result);

        return result;
    }
};

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 2};
    vector<int> nums(a, a + 3);
    Solution s;
    vector<vector<int> > ret = s.subsetsWithDup(nums);
    cout << "size is " << ret.size() << endl;
    for (auto i : ret)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

