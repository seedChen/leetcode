/**
 * @file ans.cpp
 * @brief
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 *
 * @version
 * @date 2015-07-03 15:23
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() <= 1)
            return 0;

        int currMin = prices[0];
        int* dp1 = new int[prices.size()];
        dp1[0] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            currMin = min(currMin, prices[i]);
            dp1[i] = max(dp1[i-1], prices[i] - currMin);
        }

        int currMax = prices[prices.size()-1];
        int* dp2 = new int[prices.size()];
        dp2[prices.size()-1] = 0;
        for (int i = prices.size() - 2; i >=0; i--)
        {
            currMax = max(currMax, prices[i]);
            dp2[i] = max(dp2[i+1], currMax - prices[i]);
        }

        int maxPro = -1;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i != prices.size() - 1)
                maxPro = max(maxPro, dp1[i] + dp2[i+1]);
            else
                maxPro = max(maxPro, dp1[i]);
        }

        delete []dp1;
        delete []dp2;

        return maxPro;
    }
};

