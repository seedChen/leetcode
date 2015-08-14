/**
 * @file ans.c
 * @brief
 * Implement pow(x, n).
 *
 * @version
 * @date 2015-05-30 10:47
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

double pow(double x, int n)
{
    if (x == 0)
        return 0;
    if (n < 0)
        return 1 / pow(x, -n);

    double ret = 1;
    for (; n != 0; n >>= 1, x *= x)
    {
        if (n & 1)
            ret *= x;
    }
    return ret;
}

