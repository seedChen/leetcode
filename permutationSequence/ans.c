/**
 * @file ans.c
 * @brief
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 *
 * @version
 * @date 2015-06-03 15:30
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* s, int startIdx)
{
    int i = startIdx;
    int j = strlen(s) - 1;
    while (i < j)
    {
        s[i] = s[i] + s[j];
        s[j] = s[i] - s[j];
        s[i] = s[i] - s[j];
        i++;
        j--;
    }
}

bool nextPermutation(char* s)
{
    int len = strlen(s);

    int i, j;
    for (i = len - 2; i != -1; i--)
    {
        if (s[i] < s[i + 1])
            break;
    }

    if (i != -1)
    {
        for (j = len - 1; j > i; j--)
        {
            if (s[j] > s[i])
                break;
        }
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        reverse(s, i + 1);
        return true;
    }
    else
        return false;
}

char* getPermutation(int n, int k)
{
    if (n <= 0 || k <= 0)
        return NULL;

    char *s = (char*)malloc((n + 1) * sizeof(char));
    s[n] = '\0';
    for (int i = 0; i < n; i++)
    {
        s[i] = i + 1 + '0';
    }

    for (int i = 0; i < k - 1; i++)
        if (!nextPermutation(s))
            return NULL;

    return s;
}

