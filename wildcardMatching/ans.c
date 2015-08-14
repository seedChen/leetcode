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

    char* lastStarIdx = NULL;
    char* lastSidx = NULL;

    while (*s)
    {
        if (*p != '\0' && (*s == *p || *p == '?'))
        {
            s++;
            p++;
            continue;
        }
        if (*p == '*')
        {
            lastSidx = s;
            lastStarIdx = p;
            p++;
            continue;
        }
        if (*p != *s)
        {
            if (lastStarIdx != NULL)
            {
                s = lastSidx + 1;
                lastSidx = s;
                p = lastStarIdx + 1;
                continue;
            }
        }

        return false;
    }
    while (*p == '*') p++;

    return *p == '\0';
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

