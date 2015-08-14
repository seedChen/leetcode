/**
 * @file ans.c
 * @brief
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 *
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <string.h>
#include <math.h>

int titleToNumber(char* s)
{
    if (NULL == s)
        return 0;

    long long result = 0;
    int i = strlen(s) - 1;
    int j = 0;

    for (; i >= 0; i--, j++)
    {
        if (s[i] < 'A' || s[i] > 'Z')
            return 0;

        result += (s[i] - 'A' + 1) * pow(26, j);

        if (result > (int)0x7FFFFFFF)
            return 0;
    }

    return (int)result;
}

