/**
 * @file ans.cpp
 * @brief
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 *  ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 *
 * @version
 * @date 2015-05-09 17:01
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isPalindrome(char* s)
{
    if (NULL == s)
        return false;
    if (strlen(s) == 0 || strlen(s) == 1)
        return true;

    char* i = s;
    char* j = s + strlen(s) - 1;
    do
    {
        if (*i < '0' || (*i > '9' && *i < 'A') || (*i > 'Z' && *i < 'a') || *i > 'z')
        {
            i++;
            continue;
        }
        if (*j < '0' || (*j > '9' && *j < 'A') || (*j > 'Z' && *j < 'a') || *j > 'z')
        {
            j--;
            continue;
        }
        if ((*i != *j) && (abs(*i - *j) != 'a' - 'A'))
            return false;

        i++;
        j--;
    }
    while (i < j);

    return true;
}

int main(int argc, char *argv[])
{
    printf("%d\n", isPalindrome("ab"));
    return 0;
}
