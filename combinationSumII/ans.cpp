/**
 * @file ans.cpp
 * @brief
 * Given a collection of candidate numbers (C) and a target number (T), find
 * all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order.
 * (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 *
 * @version
 * @date 2015-05-22 12:00
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    bool combinationSumHelper(vector<int>& candidates, int target, int idx, vector<vector<int> >& result, vector<int>& ans)
    {
        if (target == 0)
        {
            result.push_back(ans);
            ans.pop_back();
            return true;
        }
        else if (target < 0)
        {
            ans.pop_back();
            return false;
        }
        else
        {
            for (int i = idx; i < (int)candidates.size();)
            {
                ans.push_back(candidates[i]);
                if (!combinationSumHelper(candidates, target - candidates[i], i + 1, result, ans))
                    break;
                while(i < (int)candidates.size() - 1 && candidates[i] == candidates[i + 1])++i;
                ++i;
            }
        }

        if (!ans.empty())
            ans.pop_back();
        return true;
    }

public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int> > ret;
        if (target <= 0)
            return ret;

        vector<int> ans;
        sort(candidates.begin(), candidates.end(), less<int>());
        combinationSumHelper(candidates, target, 0, ret, ans);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    int a[] = {1, 1, 2, 5, 6, 7, 10};
    vector<int> candidates(a, a + 7);
    Solution s;
    vector<vector<int> > ret = s.combinationSum(candidates, 8);
    for (auto i : ret)
    {
        for (auto j : i)
            cout << j;
        cout << endl;
    }
    return 0;
}

