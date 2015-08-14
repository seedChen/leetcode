/**
 * @file ans.cpp
 * @brief
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 *
 * @version
 * @date 2015-05-29 11:58
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix)
    {
        if (matrix.size() == 0 || matrix.size() == 1)
            return;

        for(int i = 0, j = matrix.size() - 1; i < j; i++, j--)
        {
            for (int a = i, b = j; a < j; a++, b--)
            {
                int t = matrix[i][a];
                matrix[i][a]= matrix[b][i];
                matrix[b][i] = matrix[j][b];
                matrix[j][b] = matrix[a][j];
                matrix[a][j] = t;
            }
        }
    }
};

