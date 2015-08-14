/**
 * @file ans.cpp
 * @brief
 * Design and implement a TwoSum class. It should support the following
 * operations: add and find.
 *
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the
 * value.
 *
 * For example,
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 *
 * @version
 * @date 2015-05-13 15:38
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <map>

using namespace std;

class TwoSum
{
private:
    map<int, int> nums;
public:
    void add(int num)
    {
        if (nums.find(num) == nums.end())
            nums[num] = 1;
        else
            nums[num]++;
    }

    bool find(int value)
    {
        if (nums.empty())
            return false;
        if (!(value & 0x1))
            if (nums.find(value / 2) != nums.end() && nums.find(value / 2)->second > 1)
                return true;

        map<int, int>::iterator it = nums.begin();
        while (it->first < (value / 2 + 1) && it != nums.end())
        {
            int another = value - it->first;
            if (nums.find(another) != nums.end())
                return true;
            ++it;
        }

        return false;
    }
};

