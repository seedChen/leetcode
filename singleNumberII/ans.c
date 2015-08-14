/**
 * @file ans.c
 * @brief
 * Given an array of integers, every element appears three times except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 *
 * @version
 * @date 2015-07-27 19:24
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int singleNumber(int* nums, int numsSize)
{
    if (NULL == nums || numsSize <= 0)
        return 0;

    int ret = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < numsSize; j++)
            ret ^= nums[j];

    return ret;
}

