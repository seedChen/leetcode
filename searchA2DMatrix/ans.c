/**
 * @file ans.c
 * @brief
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 *
 * @version
 * @date 2015-06-11 15:07
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stddef.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    if (NULL == matrix || matrixRowSize <=0 || matrixColSize <= 0)
        return false;
    int endX = matrixColSize - 1;
    int endY = 0;

    while (endX >= 0 && endY < matrixRowSize)
    {
        if (target == matrix[endY][endX])
            return true;
        else if (target < matrix[endY][endX])
            endX--;
        else
            endY++;
    }

    return false;
}

