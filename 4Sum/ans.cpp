/**
 * @file ans.cpp
 * @brief
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order.
 * (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 * A solution set is:
 * (-1,  0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2,  0, 0, 2)
 *
 *
 * @version
 * @date 2015-05-14 10:57
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > result;
        if (num.size() < 4)
            return result;
        sort(num.begin(), num.end());

        for (int i = 0; i < num.size() - 3; )
        {
            for(int j = i + 1; j < num.size() - 2; )
            {
                int begin = j + 1;
                int end = num.size() - 1;
                while (begin < end)
                {
                    int sum = num[i]+ num[j] + num[begin] + num[end];
                    if (sum < target)
                    {
                        while (num[begin] == num[begin + 1] && begin < end - 1) begin++;
                        begin++;
                    }
                    else if (sum > target)
                    {
                        while (num[end] == num[end - 1] && begin < end - 1) end--;
                        end--;
                    }
                    else if (sum == target)
                    {
                        vector<int> item;
                        item.push_back(num[i]);
                        item.push_back(num[j]);
                        item.push_back(num[begin]);
                        item.push_back(num[end]);
                        result.push_back(item);

                        while (num[begin] == num[begin + 1] && begin < end - 1) begin++;
                        begin++;
                    }
                }
                while (num[j] == num[j + 1] && j < num.size() - 3) j++;
                j++;
            }
            while (num[i] == num[i + 1] && i < num.size() - 4) i++;
            i++;
        }

        return result;
    }
};
