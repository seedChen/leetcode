/**
 * @file ans.c
 * @brief
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *
 * @version
 * @date 2015-06-25 15:26
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
// TLE
bool helper(char* s1, char* s2, char* s3)
{
    if (strlen(s1) == 0 && strlen(s2) == 0 && strlen(s3))
        return true;;

    if (s3[0] == s1[0])
    {
        if (helper(s1 + 1, s2, s3 + 1))
            return true;
    }

    if (s3[0] == s2[0])
    {
        if (helper(s1, s2 + 1, s3 + 1))
            return true;
    }

    return false;
}

bool isInterleave(char* s1, char* s2, char* s3)
{
    if (NULL == s1 || NULL == s2 || NULL == s3 ||
            strlen(s3) != strlen(s1) + strlen(s2))
        return false;

    return helper(s1, s2, s3);
}

#endif

bool isInterleave(char* s1, char* s2, char* s3)
{
    int m = strlen(s1);
    int n = strlen(s2);
    if (NULL == s1 || NULL == s2 || NULL == s3 ||
            m + n != (int)strlen(s3))
        return false;


    bool* dp = (bool*)malloc((n + 1) * sizeof(bool));
    dp[0] = true;
    for (int i = 1; i < n + 1; i++)
    {
        if (s2[i-1] == s3[i-1])
            dp[i] = true;
        else
        {
            for (int j = i; j < n + 1; j++)
                dp[j] = false;
            break;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        dp[0] = (dp[0] && s1[i-1] == s3[i-1]);
        for (int j = 1; j < n + 1; j++)
        {
            if (dp[j-1])
                dp[j] = (s2[j-1] == s3[i+j-1]);
            else if (dp[j])
                dp[j] = (s1[i-1] == s3[i+j-1]);
            else
                dp[j] = false;
        }
    }

    bool ret = dp[n];
    free(dp);

    return ret;
}

int main(int argc, char *argv[])
{
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbcbcac";
    char s4[] = "aadbbbaccc";

    printf("%d\n", isInterleave(s1, s2, s3));
    printf("%d\n", isInterleave(s1, s2, s4));

    return 0;
}

