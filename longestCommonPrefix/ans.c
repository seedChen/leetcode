/**
 * @file ans.c
 * @brief
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * @version
 * @date 2015-05-07 15:59
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

char* longestCommonPrefix(char** strs, int strsSize)
{
    if (strs == NULL || strsSize <= 0)
    {
        char* ret = (char*)malloc(1);
        *ret = '\0';
        return ret;
    }

    if (strs[0] == NULL)
    {
        char* ret = (char*)malloc(1);
        *ret = '\0';
        return ret;
    }

    char* result = (char*)malloc(MAX_SIZE * sizeof(char));
    int i = 0;
    for (; ; ++i)
    {
        char c = strs[0][i];
        if (c != '\0')
        {
            int j;
            for (j = 1; j < strsSize; ++j)
                if (strs[j][i] != c)
                    goto OVER;
        }
        else
           break;
    }

OVER:
    return strncpy(result, strs[0], i);
}
