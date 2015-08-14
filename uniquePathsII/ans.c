/**
 * @file ans.c
 * @brief
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
 *
 * @version
 * @date 2015-06-08 20:20
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
    if(obstacleGridRowSize <= 0 || obstacleGridColSize <= 0)
        return 0;

    if (obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGridRowSize - 1][obstacleGridColSize - 1] == 1)
        return 0;

    int *dp = (int*)malloc(obstacleGridColSize * sizeof(int));
    dp[0] = 1;
    for (int i = 1; i < obstacleGridColSize; i++ )
    {
        if (obstacleGrid[obstacleGridRowSize - 1][obstacleGridColSize - 1 - i] == 0)
            dp[i] = dp[i - 1];
        else
        {
            dp[i] = 0;
        }
    }

    for (int i = 1; i < obstacleGridRowSize; i++)
    {
        if (obstacleGrid[obstacleGridRowSize - 1 - i][obstacleGridColSize - 1] == 0)
            dp[0] = dp[0];
        else
            dp[0] = 0;

        for (int j = 1; j < obstacleGridColSize; j++)
        {
            if (obstacleGrid[obstacleGridRowSize - 1 - i][obstacleGridColSize - 1 - j] == 0)
                dp[j] = dp[j - 1] + dp[j];
            else
                dp[j] = 0;
        }
    }

    int ret = dp[obstacleGridColSize - 1];
    free(dp);
    return ret;
}

