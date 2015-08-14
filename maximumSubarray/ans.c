/**
 * @file ans.c
 * @brief
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 * @version
 * @date 2015-05-31 16:53
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int maxSubArray(int* nums, int numsSize)
{
    if (NULL == nums || numsSize <= 0)
        return 0;

    int max = nums[0];
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (sum < 0)
            sum = nums[i];
        else
            sum += nums[i];
        if (max < sum)
            max = sum;
    }

    return max;
}

