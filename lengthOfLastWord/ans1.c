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
#include <string.h>
#include <stddef.h>

int lengthOfLastWord(char* s)
{
    if (NULL == s)
        return 0;

    int len = strlen(s);
    if (!len)
    {
        return 0;
    }

    int n = 0;
    int i = len - 1;
    while (s[i] == ' ' && i > 0) i--;

    for (; i >= 0; i--)
    {
        if (s[i] != ' ')
            n++;
        else
            return n;
    }

    return n;
}

