/**
 * @file ans.c
 * @brief
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * @version
 * @date 2015-05-19 20:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int binSearch(int* nums, int numsSize, int target)
{
    int i = 0;
    int j = numsSize - 1;
    int pos = -1;

    while(i <= j)
    {
        int m = (i + j) / 2;
        if (nums[m] > target)
        {
            j = m - 1;
        }
        else if (nums[m] < target)
        {
            i = m + 1;
        }
        else
        {
            pos = m;
            break;
        }
    }

    return pos;
}

int findKeyPos(int* nums, int numsSize, int target)
{
    int i = 0;
    int j = numsSize - 1;
    if (nums[i] < nums[j])
        return -1;

    while (i < j)
    {
        int m = (i + j) / 2;
        if (nums[m] > nums[m + 1])
            return m;
        if (nums[m] < nums[m - 1])
            return (--m);

        if (nums[m] > nums[i])
        {
            i = m + 1;
            continue;
        }
        if (nums[m] < nums[j])
        {
            j = m - 1;
            continue;
        }
    }

    return -1;
}

int search(int* nums, int numsSize, int target)
{
    if (NULL == nums || numsSize <= 0)
        return -1;

    int keyPos = findKeyPos(nums, numsSize, target);
    if (-1 == keyPos)
    {
        return binSearch(nums, numsSize, target);
    }
    else
    {
        if (nums[0] <= target && nums[keyPos >= target])
            return binSearch(nums, keyPos + 1, target);
        else if (nums[keyPos + 1] <= target && nums[numsSize - 1] >= target)
        {
            int ret = binSearch(nums + keyPos + 1, numsSize - keyPos - 1, target);
            return (ret == -1 ? -1 : keyPos + 1 + ret);
        }
        else
            return -1;
    }
}

