/**
 * @file ans.c
 * @brief
 * Given a string S and a string T, count the number of distinct subsequences
 * of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters.
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 *
 * @version
 * @date 2015-06-30 11:25
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#if 0
int helper(char* s, char* t)
{
    int lenS = strlen(s);
    int lenT = strlen(t);
    if (lenS == 0 && lenT == 0)
        return 1;

    int count = 0;
    for (int i = 0; i <= lenS - lenT; i++)
    {
        if (s[i] == t[0])
            count += helper(s + i + 1, t + 1);
    }
    return count;
}

int numDistinct(char* s, char* t)
{
    if (s == NULL || t == NULL)
        return 0;
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS == 0)
        return lenT == 0;
    else if (lenT == 0)
        return lenS == 0;

    return helper(s, t);
}
#endif

#if 0
int numDistinct(char* s, char* t)
{
    if (s == NULL || t == NULL)
        return 0;
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS == 0)
        return lenT == 0;
    else if (lenT == 0)
        return lenS == 0;

    int** dp = (int**)malloc(lenS * sizeof(int*));
    for (int i = 0; i < lenS; i++)
    {
        dp[i] = (int*)malloc(lenT * sizeof(int));
        memset(dp[i], 0, lenT * sizeof(int));
    }

    if (s[0] == t[0])
        dp[0][0] = 1;
    for (int i = 1; i < lenS; i++)
    {
        if (s[i] != t[0])
            dp[i][0] = dp[i-1][0];
        else
            dp[i][0] = dp[i-1][0] + 1;
    }

    for (int m = 1; m < lenS; m++)
    {
        for (int n = 1; n <= m && n < lenT; n++)
        {
            if (s[m] == t[n])
                dp[m][n] = dp[m-1][n] + dp[m-1][n-1];
            else
                dp[m][n] = dp[m-1][n];
        }
    }

    int ret = dp[lenS-1][lenT-1];
    for (int i = 0; i < lenS; i++)
        free(dp[i]);
    free(dp);

    return ret;
}

int main(int argc, char *argv[])
{
    char s[] = "aacaacca";
    char t[] = "ca";
    printf("%d\n", numDistinct(s, t));
    return 0;
}
#endif

int numDistinct(char* s, char* t)
{
    if (s == NULL || t == NULL)
        return 0;
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS == 0)
        return lenT == 0;
    else if (lenT == 0)
        return lenS == 0;

    int* dp = (int*)malloc((lenT + 1) * sizeof(int));
    memset(dp, 0, (lenT + 1) * sizeof(int));
    dp[0] = 1;

    for (int m = 1; m <= lenS; m++)
        for(int n = lenT; n >= 1; n--)
        {
            if(s[m-1] == t[n-1])
                dp[n] += dp[n-1];
        }

    int ret = dp[lenT];
    free(dp);

    return ret;
}

