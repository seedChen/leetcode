/**
 * @file ans.c
 * @brief
 * Write a function that takes an unsigned integer and returns the number of ’1'
 * bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
 *
 * @version
 * @date 2015-05-12 22:09
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdint.h>

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n = (n - 1) & n;
        count++;
    }

    return count;
}

