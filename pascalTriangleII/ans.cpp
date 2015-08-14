/**
 * @file ans.cpp
 * @brief
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 * @version
 * @date 2015-05-09 13:02
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <stddef.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        if (rowIndex < 0)
            return result;

        vector<int> row1;
        vector<int> row2;
        row1.push_back(1);
        vector<int>* lastRow = &row2;
        vector<int>* newRow = &row1;
        vector<int>* tmp = NULL;
        for (int i = 1; i <= rowIndex; i++)
        {
            tmp = lastRow;
            lastRow = newRow;
            newRow = tmp;
            newRow->clear();

            newRow->push_back(1);
            for (int j = 1; j < i; j++)
                newRow->push_back((*lastRow)[j - 1] + (*lastRow)[j]);
            newRow->push_back(1);
        }

        return (*newRow);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> ret = s.getRow(2);
    for (int i = 0; i < ret.size(); ++i)
    {
        cout << ret[i] << endl;
    }
    return 0;
}
