/**
 * @file ans.cpp
 * @brief
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 * @version
 * @date 2015-05-09 12:37
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > result;
        if (numRows < 1)
            return result;

        vector<int> row1;
        row1.push_back(1);
        result.push_back(row1);
        for(int i = 2; i <= numRows; ++i)
        {
            vector<int> currRow;
            vector<int> lastRow = result.back();
            currRow.push_back(1);
            for (int j = 1; j < i - 1; j++)
                currRow.push_back(lastRow[j - 1] + lastRow[j]);
            currRow.push_back(1);

            result.push_back(currRow);
        }

        return result;
    }
};
