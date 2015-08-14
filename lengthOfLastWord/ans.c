/**
 * @file ans.cpp
 * @brief
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 *
 * @version
 * @date 2015-05-09 14:55
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

int lengthOfLastWord(char* s)
{
    if (NULL == s)
        return 0;

    int count = 0;
    char* p;
    if(*s != ' ' && *s !='\0')
        p = s;
    else
        p = NULL;

    char* q = s;

    for(; *(q + 1) != '\0'; q++)
    {
        if (*q == ' ' && *(q + 1) != ' ')
            p = q + 1;
    }

    if (p == NULL)
        return 0;

    while (*p != ' ' && *p != '\0')
    {
        count++;
        p++;
    }

    return count;
}

