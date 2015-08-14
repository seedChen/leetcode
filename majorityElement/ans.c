/**
 * @file ans.c
 * @brief
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than n/2 times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * @version
 * @date 2015-05-13 16:52
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int majorityElement(int* nums, int numsSize)
{
    if (NULL == nums || numsSize < 1)
        return 0;

    int last =  nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] == last)
            count++;
        else
        {
            count--;
            if (0 == count)
            {
                last = nums[i];
                count = 1;
            }
        }

    }

    return last;
}

