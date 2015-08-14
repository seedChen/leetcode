/**
 * @file ans.c
 * @brief
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with
 * x-axis forms a container, such that the container contains the most water.
 *
 * @version
 * @date 2015-05-07 11:28
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

#define min(x, y) (x > y ? y : x)

int maxArea(int* height, int heightSize)
{
    if (NULL == height || heightSize < 1)
        return 0;

    int i = 0;
    int j = heightSize - 1;

    int minHeight = min(height[i], height[j]);
    int max = (j - i) * minHeight;

    while (i < j)
    {
        if (height[i] < height[j])
        {
            i++;
            if (height[i] > minHeight)
            {
                minHeight = min(height[i], height[j]);
                int newArea = (j - i) * minHeight;
                max = max < newArea ? newArea : max;
            }
        }
        else
        {
            j--;
            if (height[j] > minHeight)
            {
                minHeight = min(height[i], height[j]);
                int newArea = (j - i) * minHeight;
                max = max < newArea ? newArea : max;
            }
        }
    }

    return max;
}
