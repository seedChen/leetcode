/**
 * @file ans.c
 * @brief
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new
 * length.
 *
 *
 * @version
 * @date 2015-05-16 14:12
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    if (NULL == nums || numsSize <= 0)
        return 0;

    int lastAvaialbleIdx = 1;
    int flag = 0;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i-1])
            flag++;
        else
            flag = 0;

        if (flag >= 2)
            continue;
        nums[lastAvaialbleIdx++] = nums[i];
    }

    return lastAvaialbleIdx;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 1, 1, 2, 2, 3};
    int ret = removeDuplicates(a, 6);

    for (int i = 0; i < ret; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}

