/**
 * @file ans.c
 * @brief
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * @version
 * @date 2015-06-10 11:01
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

int climbStairs(int n)
{
    if (n < 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int a = 2;
    int b = 1;
    int count = 2;
    while (count < n)
    {
        int tmp = a;
        a = a + b;
        b = tmp;
        count++;
    }

    return a;
}

