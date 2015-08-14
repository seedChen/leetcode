/**
 * @file ans.c
 * @brief
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 *
 * @version
 * @date 2015-06-10 10:04
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <math.h>

// the key equation is Xi+1 = (Xi + n/Xi) / 2.
int mySqrt(int x)
{
    if (x <= 0)
        return 0;

    double last = 0;
    double curr = 1;

    while (fabs(curr - last) > 0.00001)
    {
        last = curr;
        curr = (curr + x / curr) / 2;
    }

    return (int)curr;
}

