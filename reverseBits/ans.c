/**
 * @file ans.c
 * @brief
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 *
 * @version
 * @date 2015-05-12 22:25
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdint.h>

uint32_t reverseBits(uint32_t n)
{
    n = (((n >> 1) & 0x55555555) | ((n & 0x55555555) << 1));
    n = (((n >> 2) & 0x33333333) | ((n & 0x33333333) << 2));
    n = (((n >> 4) & 0x0F0F0F0F) | ((n & 0x0F0F0F0F) << 4));
    n = (((n >> 8) & 0x00FF00FF) | ((n & 0x00FF00FF) << 8));
    n = ((n >> 16) | (n  << 16));

    return n;
}

