/**
 * @file ans.c
 * @brief
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 * @version
 * @date 2015-05-08 19:53
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdio.h>

int trailingZeroes(int n)
{
    long long nl = n;
    long long x = 5;
    long long  count = 0;
    while (nl / x > 0)
    {
        count += nl / x;
        x *= 5;
    }

    return count;
}

int main(void)
{
    printf("%d\n", trailingZeroes(1808548329));
    return 0;
}
