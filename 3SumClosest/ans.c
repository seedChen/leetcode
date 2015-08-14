/**
 * @file ans.c
 * @brief
 * Given an array S of n integers, find three integers in S such that the sum
 * is closest to a given number, target. Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 * @version
 * @date 2015-05-08 09:51
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b ? 1 : -1;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    if (NULL == nums || numsSize < 3)
        return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int i, j, k;
    int ret = nums[0] + nums[1] + nums[2];
    int distance = abs(ret - target);
    for (i = 0; i < numsSize - 2; )
    {
        j = i + 1;
        k = numsSize - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (abs(sum - target) < distance)
            {
                ret = sum;
                distance = abs(sum - target);
            }

            if (sum < target)
            {
                while (nums[j] == nums[j + 1] && j < k - 1) j++;
                j++;
            }
            else if (sum > target)
            {
                while (nums[k] == nums[k - 1] && j < k - 1) k--;
                k--;
            }
            else
            {
                return sum;
            }
        }
        while(nums[i] == nums[i + 1] && i < numsSize - 3) i++;
        i++;
    }

    return ret;
}

