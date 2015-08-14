/**
 * @file ans.cpp
 * @brief
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 * @version
 * @date 2015-06-03 11:21
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector< vector<int> > result(n, vector<int> (n, 0));
        if (n <= 0)
            return result;

        int count = 1;
        for (int i = 0; i * 2 < n; i++)
        {
            int start = i;
            int endX = n - 1 - i;
            int endY = n - 1 - i;
            if (start == endX)
            {
                for (int j = start; j <= endY; j++)
                    result[j][start] = count++;
            }
            else if (start == endY)
            {
                for (int j = start; j <= endX; j++)
                    result[start][j] = count++;
            }
            else
            {
                for (int j = start; j <= endX - 1; j++)
                    result[start][j] = count++;
                for (int j = start; j <= endY - 1; j++)
                    result[j][endX] = count++;
                for (int j = endX; j >= start + 1; j--)
                    result[endY][j] = count++;
                for (int j = endY; j >= start + 1; j--)
                    result[j][start] = count++;
            }
        }

        return result;
    }
};

