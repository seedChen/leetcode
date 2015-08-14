/**
 * @file ans.cpp
 * @brief
 * Given a sorted integer array without duplicates, return the summary of
 * its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 * @version
 * @date 2015-08-14 09:40
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    string makeRange(int left, int right)
    {
        if (left == right)
            return to_string(left);
        else
            return to_string(left) + "->" + to_string(right);
    }

public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 0)
            return result;

        int last = nums[0];
        int next = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (next != nums[i] - 1)
            {
                result.push_back(makeRange(last, next));
                last = nums[i];
            }
            next = nums[i];
        }

        result.push_back(makeRange(last, next));

        return result;
    }
};

