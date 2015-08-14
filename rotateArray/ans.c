/**
 * @file ans.c
 * @brief
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 *
 * @version
 * @date 2015-05-13 10:24
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

void reverse(int *nums, int numsSize)
{
    int i = 0;
    int j = numsSize - 1;
    while(i < j)
    {
        nums[i] = nums[i] + nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];

        i++;
        j--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    reverse(nums, numsSize - k);
    reverse(nums + numsSize - k, k);
    reverse(nums, numsSize);
}

