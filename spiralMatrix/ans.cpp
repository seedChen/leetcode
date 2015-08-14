/**
 * @file ans.cpp
 * @brief
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 *
 * @version
 * @date 2015-05-31 17:26
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return result;

        for (int i = 0; i * 2 < (int)matrix.size() && i * 2 < (int)matrix[0].size(); i++)
        {
            int j = i;
            int k1 = matrix.size() - i - 1;
            int k2 = matrix[0].size() - 1 - i;

            if (j == k1)
            {
                for (int n = j; n <= k2; n++)
                    result.push_back(matrix[j][n]);
            }
            else if (j == k2)
            {
                for (int n = j; n <= k1; n++)
                    result.push_back(matrix[n][j]);
            }
            else
            {
                for (int n = j; n <= k2 - 1; n++)
                    result.push_back(matrix[j][n]);
                for (int n = j; n <= k1 - 1; n++)
                    result.push_back(matrix[n][k2]);
                for (int n = k2; n >= j + 1; n--)
                    result.push_back(matrix[k1][n]);
                for (int n = k1; n >= j + 1; n--)
                    result.push_back(matrix[n][j]);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    int a1[] = {6, 9, 7};

    vector<int> v1(a1, a1 + 3);

    vector<vector<int> > matrix;
    matrix.push_back(v1);

    Solution s;
    vector<int> ret = s.spiralOrder(matrix);
    for (auto i : ret)
        cout << i << endl;

    return 0;
}

