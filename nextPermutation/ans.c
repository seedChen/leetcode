/**
 * @file ans.c
 * @brief
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 * @version
 * @date 2015-05-17 20:13
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

void reverse(int* nums, int numsSize)
{
    int i = 0;
    int j = numsSize - 1;
    while (i < j)
    {
        nums[i] = nums[i] + nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];
        i++;
        j--;
    }
}

void nextPermutation(int* nums, int numsSize)
{
    if (NULL == nums || numsSize < 0)
        return;

    int i, j;
    for (i = numsSize - 2; i != -1; i--)
    {
        if (nums[i] < nums[i + 1])
            break;
    }

    if (i != -1)
    {
        for (j = numsSize - 1; j > i; j--)
        {
            if (nums[j] > nums[i])
                break;
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    reverse(nums + i + 1, numsSize - i - 1);
}

