/**
 * @file ans.c
 * @brief
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping you
 * from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent houses
 * were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * @version
 * @date 2015-05-12 17:51
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

#define max(x, y) (x > y) ? x : y

int rob(int* nums, int numsSize)
{
    if (NULL == nums)
        return 0;
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];

    int f0 = 0;
    int f1 = nums[0];

    int fSub2 = f0;
    int fSub1 = f1;
    int fn = 0;

    for (int i = 1; i < numsSize; i++)
    {
        fn = max(fSub1, fSub2 + nums[i]);
        fSub2 = fSub1;
        fSub1 = fn;
    }

    return fn;
}

