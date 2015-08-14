/**
 * @file ans.c
 * @brief
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * @version
 * @date 2015-05-16 15:39
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string.h>
#include <stdlib.h>

void getNext(char* p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            ++j;
            ++k;
            if (p[j] != p[k])
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
        {
            k = next[k];
        }
    }
}


int strStr(char* haystack, char* needle)
{
    if (haystack == NULL || needle == NULL)
        return -1;
    int i = 0;
    int j = 0;
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    int* next = (int*)malloc(nLen * sizeof(int));
    getNext(needle, next);

    while (i < hLen && j < nLen)
    {
        if (j == -1 || haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j == nLen)
        return i - j;
    else
        return -1;

}

