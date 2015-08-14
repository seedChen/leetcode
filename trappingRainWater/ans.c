/**
 * @file ans.c
 * @brief
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 * @version
 * @date 2015-05-26 16:19
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

int trap(int* height, int heightSize)
{
    if (NULL == height || heightSize <= 0)
        return 0;

    int maxIdx = 0;
    for (int i = 1; i < heightSize; ++i)
    {
        if (height[maxIdx] < height[i])
            maxIdx = i;
    }

    if (height[maxIdx] == 0)
        return 0;

    int result = 0;
    // from left
    int maxLeft = 0;
    for (int i = 0; i < maxIdx; ++i)
    {
        if (maxLeft > height[i])
            result += maxLeft - height[i];
        if (maxLeft < height[i])
            maxLeft = height[i];
    }

    // from right
    int maxRight = 0;
    for (int i = heightSize - 1; i > maxIdx; --i)
    {
        if (maxRight > height[i])
            result += maxRight - height[i];
        if (maxRight < height[i])
            maxRight = height[i];
   }

    return result;
}

int main(int argc, char *argv[])
{
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d", trap(height, 12));

    return 0;
}

