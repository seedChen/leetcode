/**
 * @file ans.c
 * @brief
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in place.
 *
 * @version
 * @date 2015-06-11 11:48
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
    if (NULL == matrix || matrixRowSize <= 0 || matrixColSize <=0)
        return;

    int flag0Row = 0;
    int flag0Col = 0;

    for (int i = 0; i < matrixColSize; i++)
        if (matrix[0][i] == 0)
        {
            flag0Row = 1;
            break;
        }

    for (int i = 0; i < matrixRowSize; i++)
        if (matrix[i][0] == 0)
        {
            flag0Col = 1;
            break;
        }

    for (int i = 1; i < matrixRowSize; i++)
        for (int j = 1; j < matrixColSize; j++)
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }

    for (int i = 1; i < matrixRowSize; i++)
        if (matrix[i][0] == 0)
            for (int j = 1; j < matrixColSize; j++)
                matrix[i][j] = 0;

    for (int i = 1; i < matrixColSize; i++)
        if (matrix[0][i] == 0)
            for (int j = 1; j < matrixRowSize; j++)
                matrix[j][i] = 0;

    if (flag0Row)
        for (int i = 0; i < matrixColSize; i++)
            matrix[0][i] = 0;

    if (flag0Col)
        for (int i = 0; i < matrixRowSize; i++)
            matrix[i][0] = 0;
}

