/**
 * @file ans.c
 * @brief
 * Given a sorted array, remove the duplicates in place such that each element
 * appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively. It doesn't matter what you leave beyond the new
 * length.
 *
 * @version
 * @date 2015-05-16 14:12
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int removeDuplicates(int* nums, int numsSize)
{
    if (NULL == nums || numsSize <= 0)
        return 0;

    int lastAvaialbleIdx = 1;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] != nums[i + 1])
            nums[lastAvaialbleIdx++] = nums[i + 1];
    }

    return lastAvaialbleIdx;
}

