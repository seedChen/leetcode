/**
 * @file ans.cpp
 * @brief
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the difference between nums[i] and nums[j]
 * is at most t and the difference between i and j is at most k.
 *
 * @version
 * @date 2015-08-15 14:46
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k < 1 || t < 0)
            return false;
        map<long long, long long> hash;
        long long lk = k;
        long long lt = t;
        for (long long i = 0; i < nums.size(); i++)
        {
            auto start = hash.lower_bound(nums[i] - lt);
            auto end = hash.upper_bound(nums[i] + lt);
            for (auto j = start; j != end; ++j)
            {
                if (i - j->second <= lk)
                    return true;
            }
            hash[nums[i]] = i;
        }

        return false;
    }
};

