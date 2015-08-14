/**
 * @file ans.c
 * @brief
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * @version
 * @date 2015-06-09 14:58
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>
#include <stddef.h>

#define min(x, y) x < y ? x : y

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    if (NULL == grid || gridRowSize <= 0 || gridColSize <= 0)
        return 0;

    int* dp = (int*)malloc(gridColSize * sizeof(int));
    dp[0] = grid[gridRowSize - 1][gridColSize - 1];
    for (int i = 1; i < gridColSize; i++)
        dp[i] = grid[gridRowSize - 1][gridColSize - 1 - i] + dp[i - 1];

    for (int i = 1; i < gridRowSize; i++)
    {
        dp[0] = grid[gridRowSize - 1 - i][gridColSize - 1] + dp[0];
        for (int j = 1; j < gridColSize; j++)
        {
            dp[j] = (min(dp[j], dp[j - 1])) + grid[gridRowSize - 1 - i][gridColSize - 1 - j];
        }
    }

    int ret = dp[gridColSize - 1];
    free(dp);
    return ret;
}

int main(int argc, char *argv[])
{
    int a[2] = {1, 2};
    int b[2] = {1, 1};
    int *c[2] = {a, b};
    minPathSum(c, 2, 2);

    return 0;
}
