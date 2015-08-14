/**
 * @file ans.c
 * @brief
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 *
 * @version
 * @date 2015-05-19 20:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

int search(int* nums, int numsSize, int target)
{
        int start = 0, end = numsSize - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end])
                start = mid + 1;
            else if (nums[mid] < nums[end])
                end = mid;
            else
            {
                int minIdx = start;
                for (int i = start + 1; i <= end; i++)
                {
                    if (nums[i] < nums[i-1])
                        minIdx = i;
                }
                start = minIdx;
                break;
            }
        }

        int rot = start;
        start = 0;
        end = numsSize - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int realmid = (mid + rot) % numsSize;

            if (nums[realmid] == target)
                return true;
            else if(nums[realmid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return false;
}

int main(int argc, char *argv[])
{
    int a[] = {1, 3, 1, 1, 1};
    search(a, 5, 3);
    return 0;
}

