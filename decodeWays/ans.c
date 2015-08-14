/**
 * @file ans.c
 * @brief
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.)
 *
 * @version
 * @date 2015-06-18 10:06
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string.h>
#include <stdio.h>

int numDecodings(char* s)
{
    int len = strlen(s);
    if (NULL == s || len == 0)
        return 0;
    int n_2 = 1;
    int n_1 = 1;
    int n = 1;
    if (s[0] <= '0' || s[0] > '9')
        return 0;

    for (int i = 1; i < len; i++)
    {
        if (s[i] == '0')
        {
            if (s[i-1] == '0' || s[i-1] >= '3')
                return 0;
            else if (s[i-1] > '0' && s[i-1] < '3')
                n = n_2;
        }
        else if (s[i] > '0' && s[i] < '7')
        {
            if (s[i-1] == '0')
                n = n_1;
            else if (s[i-1] > '0' && s[i-1] < '3')
                n = n_1 + n_2;
            else if (s[i-1] >= '3')
                n = n_1;
        }
        else if (s[i] >= '7' && s[i] <= '9')
        {
            if (s[i-1] == '0')
                n = n_1;
            else if (s[i-1] == '1')
                n = n_1 + n_2;
            else if (s[i-1] >= '2')
                n = n_1;
        }
        else
            return 0;

        n_2 = n_1;
        n_1 = n;
    }

    return n;
}

int main(int argc, char *argv[])
{
    char s[] = "12";
    printf("%d\n", numDecodings(s));
    return 0;
}

