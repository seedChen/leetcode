/**
 * @file ans.c
 * @brief
 * Given two words word1 and word2, find the minimum number of steps required
 * to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
 *
 * @version
 * @date 2015-06-10 16:24
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define min(x, y) (x < y ? x : y)

int minDistance(char* word1, char* word2)
{
    int m = strlen(word1);
    int n = strlen(word2);
    if (NULL == word1 || m == 0)
        return n;
    else if (NULL == word2 || n == 0)
        return m;

    int** dp;
    dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    dp[0][0] = word1[0] == word2[0] ? 0 : 1;

    int flag = word1[0] == word2[0] ? 1 : 0; // check if the first char could be matched.
    for (int i = 1; i < n; i++)
    {
        if (flag)
        {
            dp[0][i] = i;
        }
        else
        {
            if (word1[0] == word2[i])
            {
                dp[0][i] = i;
                flag = 1;
            }
            else
                dp[0][i] = i + 1;
        }
    }

    flag = word1[0] == word2[0] ? 1 : 0;
    for (int i = 1; i < m; i++)
    {
        if (flag)
        {
            dp[i][0] = i;
        }
        else
        {
            if (word1[i] == word2[0])
            {
                dp[i][0] = i;
                flag = 1;
            }
            else
                dp[i][0] = i + 1;
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + (word1[i] == word2[j] ? 0 : 1));
        }
    }

    int result = dp[m-1][n-1];
    for (int i = 0; i < m; i++)
        free(dp[i]);
    free(dp);

    return  result;
}

// another solution, solve the corner case.
#if 0

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = word1.length() + 1;
        int col = word2.length() + 1;
        
        vector<vector<int> > f(row, vector<int>(col));

        for (int i = 0; i < row; i++)
            f[i][0] = i;

        for (int i = 0; i < col; i++)
            f[0][i] = i;

        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++){
                if (word1[i-1] == word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else
                    f[i][j] = f[i-1][j-1] + 1;
                f[i][j] = min(f[i][j], min(f[i-1][j]+1, f[i][j-1]+1));
            }

        return f[row-1][col-1];
    }
};

#endif

int main(int argc, char *argv[])
{
    char* s1 = "sea";
    char* s2 = "ate";

    printf("%d\n", minDistance(s1, s2));

    return 0;
}

