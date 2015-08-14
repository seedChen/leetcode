/**
 * @file ans.c
 * @brief
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will stay)
 * , or it loops endlessly in a cycle which does not include 1. Those numbers
 * for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 * @version
 * @date 2015-05-12 17:16
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdbool.h>

bool isHappy(int n)
{
    if (n < 1)
        return false;

    bool isAppeared[9 * 9 * 10] = {false};
    int sum = 0;

    while (true)
    {
        while (n)
        {
            int i = n % 10;
            sum += i * i;
            n /= 10;
        }

        if (1 == sum)
            return true;
        else if (isAppeared[sum] == true)
            return false;

        isAppeared[sum] = true;
        n = sum;
        sum = 0;
    }
}

