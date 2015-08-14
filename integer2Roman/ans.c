/**
 * @file ans.c
 * @brief
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * @version
 * @date 2015-05-07 11:51
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* intToRoman(int num)
{
    int digit[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char* roman[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    char* result = (char*)malloc(50 * sizeof(char));
    memset(result, 0, 50);

    int i = 12;
    while (num != 0)
    {
        if (num - digit[i] >= 0)
        {
            num = num - digit[i];
            strcat(result, roman[i]);
        }
        else
            --i;
    }

    return result;
}

int main(void)
{
    printf("%s", intToRoman(3999));
}
