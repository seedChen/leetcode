/**
 * @file ans.c
 * @brief
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 * @version
 * @date 2015-05-20 20:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int searchInsert(int* nums, int numsSize, int target)
{
    if (NULL == nums || numsSize <= 0)
        return 0;
    if (nums[0] > target)
        return 0;
    if (nums[numsSize - 1] < target)
        return numsSize;

    int i = 0;
    int j = numsSize - 1;
    int m = - 1;
    while (i <= j)
    {
        m = (i + j) / 2;
        if (nums[m] < target)
            i = m + 1;
        else if (nums[m] > target)
            j = m - 1;
        else
            return m;
    }

    if (nums[m] < target)
        return m + 1;
    else // (nums[m] > target)
        return m;
}

