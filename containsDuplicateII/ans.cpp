/**
 * @file ans.cpp
 * @brief
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and
 * the difference between i and j is at most k.
 *
 * @version
 * @date 2015-08-15 13:56
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 1)
            return false;

        unordered_map<int, int> hash; // unordered_map is much faster.
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(nums[i]) != hash.end())
            {
                if (i - hash[nums[i]] <= k)
                    return true;
            }
            hash[nums[i]] = i;
        }

        return false;
    }
};
