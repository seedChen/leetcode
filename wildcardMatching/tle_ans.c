/**
 * @file ans.c
 * @brief
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 *
 * @version
 * @date 2015-05-27 17:17
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

bool isMatch(char* s, char* p)
{
    if (NULL == s || NULL == p)
        return false;

    // printf("%c\n", *p);

    if (*p == '\0')
        return *s == '\0';

    while (*p != '\0' && *p == '*' && *(p + 1) == '*')
        p++;

    if (*p != '*')
    {
        if (*p == *s || (*p == '?' && *s != '\0'))
            return isMatch(s + 1, p + 1);
        else
            return false;
    }
    else
    {
        while (*s != '\0')
        {
            if (isMatch(s, p + 1))
                return true;
            s++;
        }
    }

    return isMatch(s, p + 1);
}

int main(int argc, char *argv[])
{
    // char* s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    // char* p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    char* s = "ab";
    char* p = "*?";
    printf("%d\n", isMatch(s, p));

    return 0;
}

