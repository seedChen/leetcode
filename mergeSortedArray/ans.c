/**
 * @file ans.c
 * @brief
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2. The number of elements
 * initialized in nums1 and nums2 are m and n respectively.
 *
 * @version
 * @date 2015-06-17 10:46
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    if (nums1 == NULL)
    {
        nums1 = nums2;
        return;
    }
    if (nums2 == NULL)
        return;

    int i = m + n - 1;
    int j = m - 1;
    int k = n - 1;
    while (i >= 0 && j >= 0 && k >= 0)
    {
        if (nums1[j] > nums2[k])
        {
            nums1[i] = nums1[j];
            j--;
        }
        else
        {
            nums1[i] = nums2[k];
            k--;
        }
        i--;
    }

    if (k >= 0)
    {
        while (i >= 0 && k >= 0)
        {
            nums1[i] = nums2[k];
            i--;
            k--;
        }
    }
}

