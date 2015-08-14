/**
 * @file ans.c
 * @brief
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 * @version
 * @date 2015-05-26 11:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize)
{
    if (NULL == nums || numsSize <= 0)
        return 1;

    for (int i = 0; i < numsSize; ++i)
    {
        while (nums[i] >= 0 && nums[i] != i && nums[i] < numsSize && nums[i] != nums[nums[i]])
        {
            int tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;
        }
    }

    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] != i)
            return i;
    }

    if (nums[0] == numsSize)
        return numsSize + 1;
    else
        return numsSize;
}

int main(int argc, char *argv[])
{
    int a[] = {3, 4, -1, 1};
    int b[] = {1, 2, 3, 4};
    int c[] = {1, 2, 3, -4};
    printf("%d", firstMissingPositive(a, 4));
    printf("%d", firstMissingPositive(b, 4));
    printf("%d", firstMissingPositive(c, 4));

    return 0;
}
