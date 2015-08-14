/**
 * @file ans.c
 * @brief
 * Say you have an array for which the ith element is the price of
 * a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction
 * (ie, buy one and sell one share of the stock), design an algorithm
 * to find the maximum profit.
 *
 * @version
 * @date 2015-07-02 10:44
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <stdio.h>

#define max(x, y) x > y ? x : y

int maxProfit(int* prices, int pricesSize)
{
    if (NULL == prices || pricesSize == 0)
        return 0;

    int maxProfit = 0;
    int minPrice = prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] > minPrice)
        {
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}

int main(int argc, char *argv[])
{
    int prices[] = {1, 2};
    printf("%d\n", maxProfit(prices, 2));
    return 0;
}

