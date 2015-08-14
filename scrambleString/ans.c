/**
 * @file ans.c
 * @brief
 * Given a string s1, we may represent it as a binary tree by partitioning it to
 * two non-empty substrings recursively.
 *
 * Below is one possible representation of s1 = "great":
 *
 *     great
 *     /    \
 *    gr    eat
 *   / \    /  \
 *  g   r  e   at
 *             / \
 *            a   t
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 *
 * For example, if we choose the node "gr" and swap its two children,
 * it produces a scrambled string "rgeat".
 *
 *              rgeat
 *              /    \
 *             rg    eat
 *            / \    /  \
 *           r   g  e   at
 *                      / \
 *                     a   t
 * We say that "rgeat" is a scrambled string of "great".
 *
 * Similarly, if we continue to swap the children of nodes "eat" and "at",
 * it produces a scrambled string "rgtae".
 *
 *              rgtae
 *              /    \
 *             rg    tae
 *            / \    /  \
 *           r   g  ta  e
 *                 / \
 *                t   a
 * We say that "rgtae" is a scrambled string of "great".
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 *
 * @version
 * @date 2015-06-16 15:42
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

bool helper(char* s1, char* s2, int len, int* hash)
{
    if (strncmp(s1, s2, len) == 0)
        return true;

    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (hash[s1[i]] >= 0)
            count++;
        else
            count--;
        hash[s1[i]]++;

        if (hash[s2[i]] <= 0)
            count++;
        else
            count--;
        hash[s2[i]]--;

        if (count == 0 && i != len - 1)
        {
            bool ret = helper(s1, s2, i + 1, hash) &&
                helper(s1 + i + 1, s2 + i + 1, len - i - 1, hash);
            if (ret)
                return true;
        }
    }
    if (count != 0)
        return false;

    for (int i = 0; i < len; i++)
    {
        if (hash[s1[i]] >= 0)
            count++;
        else
            count--;
        hash[s1[i]]++;

        if (hash[s2[len - i - 1]] <= 0)
            count++;
        else
            count--;
        hash[s2[len - i - 1]]--;

        if (count == 0 && i != len - 1)
        {
            return helper(s1, s2 + len - i - 1, i + 1, hash) &&
                helper(s1 + i + 1, s2, len - i - 1, hash);
        }

    }
    if (count != 0)
        return false;

    return false;
}

bool isScramble(char* s1, char* s2)
{
    if (NULL == s1 || NULL == s2)
        return false;

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 == 0 || len2 == 0 || len1 != len2)
        return false;

    int hash[256] = {0};

    return helper(s1, s2, len1, hash);
}

int main(int argc, char *argv[])
{
    char s1[] = "acegneonzmkmpnsjzjhxwnpqffzzto";
    // char s2[] = "rgeat";
    // char s3[] = "rgtae";
    char s4[] = "oatzzffqpnwcxhejzjsnpmkmzngneo";
    // printf("%d\n", isScramble(s1, s2));
    // printf("%d\n", isScramble(s1, s3));
    printf("%d\n", isScramble(s1, s4));

    return 0;
}

