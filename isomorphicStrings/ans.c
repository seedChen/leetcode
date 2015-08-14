/**
 * @file ans.c
 * @brief
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 *
 * @version
 * @date 2015-05-12 14:29
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdbool.h>
#include <stddef.h>

bool isIsomorphic(char* s, char* t)
{
    if (NULL == s || t == NULL)
        return false;

    char map[256] = {'\0'};
    bool isMapped[256] = {false};
    char* i = s;
    char* j = t;

    while (*i != '\0' && *j != '\0')
    {
        if (map[*i] == *j)
        {
            i++;
            j++;
        }
        else if (map[*i] == '\0')
        {
            if (isMapped[*j])
                return false;
            map[*i] = *j;
            isMapped[*j] = true;
            i++;
            j++;
        }
        else
            return false;
    }

    return true;
}

