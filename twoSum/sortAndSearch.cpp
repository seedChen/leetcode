/**
 * @file sortAndSearch.cpp
 * @brief
 * Given an array of integers, find two numbers such that they add up to a
 * specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2. Please note that
 * your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 * ans: solve by sort then search
 *
 * @version
 * @date 2015-04-12 13:27
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

typedef struct
{
    int num;
    int pos;
} item;

bool cmp(const item &i, const item &j)
{
    return i.num < j.num;
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<item> items;
        for (int n = 0; n < (int)numbers.size(); ++n)
        {
            item i;
            i.num = numbers[n];
            i.pos = n;
            items.push_back(i);
        }
        sort(items.begin(), items.end(), cmp);

        int i = 0;
        int j = items.size() - 1;
        vector<int> ret;

        while (i != j)
        {
            int curr = items[i].num + items[j].num;
            if (curr > target)
                --j;
            else if (curr < target)
                ++i;
            else // i + j == target
            {
                if (items[i].pos < items[j].pos)
                {
                    ret.push_back(items[i].pos + 1);
                    ret.push_back(items[j].pos + 1);
                }
                else
                {
                    ret.push_back(items[j].pos + 1);
                    ret.push_back(items[i].pos + 1);
                }
                return ret;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    int nums[] = {11, 7, 2, 15};
    vector<int> example(nums, nums + 4);
    int target1 = 9;
    int target2 = 20;
    vector<int> ret1;
    vector<int> ret2;

    Solution s;
    ret1 = s.twoSum(example, target1);
    ret2 = s.twoSum(example, target2);
    if (ret1.empty())
        cout << "no result" << endl;
    else
        cout << ret1[0] << ' ' << ret1[1] << endl;
    if (ret2.empty())
        cout << "no result" << endl;
    else
        cout << ret2[0] << ' ' << ret2[1] << endl;

    return 0;
}

