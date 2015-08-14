/**
 * @file ans.c
 * @brief
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave
 * beyond the new length.
 *
 * @version
 * @date 2015-05-16 14:28
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int removeElement(int* nums, int numsSize, int val)
{
    if (NULL == nums || numsSize <= 0)
        return 0;

    int lastAvaiableIdx = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
            nums[lastAvaiableIdx++] = nums[i];
    }

    return lastAvaiableIdx;
}

