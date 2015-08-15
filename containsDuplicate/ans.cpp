/**
 * @file ans.cpp
 * @brief
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice
 * in the array, and it should return false if every element is distinct.
 *
 * @version
 * @date 2015-08-15 13:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;
        set<int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            auto ret = hash.insert(nums[i]);
            if (!ret.second)
                return true;
        }
        return false;
    }
};

