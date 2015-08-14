/**
 * @file ans.c
 * @brief
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white,
 * and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * @version
 * @date 2015-06-11 15:27
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

void sortColors(int* nums, int numsSize)
{
    if (nums == NULL || numsSize <= 0)
        return;

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
            count0++;
        else if(nums[i] == 1)
            count1++;
        else if (nums[i] == 2)
            count2++;
        else
            return;
    }

    int i = 0;
    for (; i < count0; i++)
        nums[i] = 0;
    for (; i < count0 + count1; i++)
        nums[i] = 1;
    for (; i < count0 + count1 + count2; i++)
        nums[i] = 2;
}

