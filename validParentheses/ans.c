/**
 * @file ans.cpp
 * @brief
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']'
 * , determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not.
 *
 * @version
 * @date 2015-05-14 15:36
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isValid(char* s)
{
    if (NULL == s)
        return false;

    int len = strlen(s);
    if (len & 0x1)
        return false;

    char* stack = (char*)malloc((len / 2 + 1) * sizeof(char));
    int topIdx = -1;
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        switch (c)
        {
            case '(':
            case '[':
            case '{':
                stack[topIdx + 1] = c;
                topIdx++;
                break;
            case ')':
                if (topIdx == -1)
                    return false;
                else
                    if (stack[topIdx] == '(')
                    {
                        topIdx--;
                        continue;
                    }
                    else
                        return false;
            case ']':
                if (topIdx == -1)
                    return false;
                else
                    if (stack[topIdx] == '[')
                    {
                        topIdx--;
                        continue;
                    }
                    else
                        return false;
            case '}':
                if (topIdx == -1)
                    return false;
                else
                    if (stack[topIdx] == '{')
                    {
                        topIdx--;
                        continue;
                    }
                    else
                        return false;
            default:
                return false;
        }

        if (topIdx == len / 2)
            return false;
    }

    if (topIdx == -1)
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    char* s = "()[]{}";
    printf("%d", isValid(s));

    return 0;
}

