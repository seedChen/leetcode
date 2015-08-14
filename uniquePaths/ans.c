/**
 * @file ans.c
 * @brief
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * @version
 * @date 2015-06-08 20:03
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>

int uniquePaths(int m, int n)
{
    if(m <= 0 || n <= 0)
        return 0;

    int **dp = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++)
    {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    dp[0][0] = 1;
    for(int i = 1; i < m; i++)
        dp[i][0] = 1;
    for(int j = 1; j < n; j++)
        dp[0][j] = 1;
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    int res = dp[m-1][n-1];

    for(int i = 0; i < m; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return res;
}

