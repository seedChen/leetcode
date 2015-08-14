/**
 * @file ans.c
 * @brief
 * Say you have an array for which the ith element is the price of
 * a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at the
 * same time (ie, you must sell the stock before you buy again).
 *
 * @version
 * @date 2015-07-02 11:07
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

int maxProfit(int* prices, int pricesSize)
{
    if (NULL == prices || pricesSize <= 1)
        return 0;

    int maxProfit = 0;
    int i = 1;
    int buy, sell;
    while (i < pricesSize)
    {
        while (prices[i-1] >= prices[i] && i < pricesSize) i++;
        if (i < pricesSize)
            buy = prices[i-1];
        else
            break;

        while (prices[i-1] <= prices[i] && i < pricesSize) i++;
        sell = prices[i-1];

        maxProfit = maxProfit + (sell - buy);
    }

    return maxProfit;
}

int main(int argc, char *argv[])
{
    int prices[] = {1, 2, 4};
    printf("%d\n", maxProfit(prices, 3));
    return 0;
}

