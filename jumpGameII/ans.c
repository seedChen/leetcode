/**
 * @file ans.c
 * @brief
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)]
 *
 * @version
 * @date 2015-05-28 12:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int jump(int* nums, int numsSize)
{
    if (NULL == nums || numsSize < 0)
        return 0;

    int step = 0;
    int last = 0;
    int curr = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (last < i)
        {
            step++;
            last = curr;
        }
        curr = curr > nums[i] + i ? curr : nums[i] + i;
    }

    return step;
}

