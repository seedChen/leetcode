/**
 * @file ans.c
 * @brief
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 *
 *
 * @version
 * @date 2015-05-16 16:09
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
    if (divisor == 0)
        return INT_MAX;

    bool isMinus = false;
    if (dividend < 0)
        isMinus = !isMinus;
    if (divisor < 0)
        isMinus = !isMinus;

    long long dd = llabs((long long)dividend);


    long long result = 0;

    while (1)
    {
        long long dr = llabs((long long)divisor);
        if (dd < dr)
            break;

        long long count = 1;
        while (dr <= dd)
        {
            dr <<= 1;
            count <<= 1;
        }
        dr >>= 1;
        count >>= 1;

        result += count;
        dd = dd - dr;
    }

    if (isMinus)
        return (0 - result) < INT_MIN ? INT_MIN : (0 - result);
    else
        return result > INT_MAX ? INT_MAX : result;

}

