/**
 * @file ans.c
 * @brief
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.]
 *
 * @version
 * @date 2015-05-28 12:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdbool.h>
#include <stddef.h>

bool canJump(int* nums, int numsSize)
{
    if (NULL == nums || numsSize < 0)
        return 0;

    int last = 0;
    int curr = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (last < i)
        {
            if (curr == last)
                return false;
            last = curr;
        }

        curr = curr > nums[i] + i ? curr : nums[i] + i;
    }

    return true;
}

