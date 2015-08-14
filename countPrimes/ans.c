/**
 * @file ans.c
 * @brief
 * Description:
 *
 * Count the number of prime numbers less than a non-negative number, n
 *
 * click to show more hints.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test
 * cases.
 *
 * @version
 * @date 2015-05-09 18:17
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>

int countPrimes(int n)
{
    n--;
    if (n < 2)
        return 0;
    int count = 1;
    char* isPrime;

    int size = 0;
    if (n & 0x1)
    {
        size = n / 2 * sizeof(char);
        isPrime = (char*)malloc(size);
    }
    else
    {
        size = (n / 2 - 1) * sizeof(char);
        isPrime = (char*)malloc(size);
    }

    memset(isPrime, 1, size);

    int sqrtN = sqrt(n);
    for (int i = 0; 2 * i + 3 <= sqrtN; i++)
        if (isPrime[i])
            for (int j = 3; j * (2 * i + 3) <= n; j += 2)
                isPrime[(j * (2 * i + 3) - 3) / 2] = 0;

    for (int i = 0; i < size; i++)
        if (isPrime[i] == 1)
            count++;

    return count;
}
