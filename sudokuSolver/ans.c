/**
 * @file ans.c
 * @brief
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 * @version
 * @date 2015-05-21 11:30
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdbool.h>
#include <stddef.h>

bool check(char** board, int x, int y)
{
    char c = board[y][x];

    // check row
    for (int i = 0; i < 9; ++i)
    {
        if (i != x && c == board[y][i])
            return false;
    }

    // check col
    for (int i = 0; i < 9; ++i)
    {
        if (i != y && c == board[i][x])
            return false;
    }

    // check 3x3
    int originI = (x / 3) * 3;
    int originJ = (y / 3) * 3;
    for (int i = originI ; i < originI + 3; ++i)
        for (int j = originJ; j < originJ + 3; ++j)
        {
            if (i == x && j == y)
                continue;
            if (c == board[j][i])
                return false;
        }

    return true;
}

bool solve(char** board)
{
    for (int y = 0; y < 9; y++)
        for (int x = 0; x < 9; x++)
        {
            if (board[y][x] == '.')
            {
                for (int i = 1; i < 10; ++i)
                {
                    board[y][x] = '0' + i;
                    if (check(board, x, y) && solve(board))
                        return true;
                    board[y][x] = '.';
                }
                return false;
            }
        }

    return true;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize)
{
    if (NULL == board)
        return;
    solve(board);
}

int main(int argc, char *argv[])
{
    char s1[] = "..9748...";
    char s2[] = "7........";
    char s3[] = ".2.1.9...";
    char s4[] = "..7...24.";
    char s5[] = ".64.1.59.";
    char s6[] = ".98...3..";
    char s7[] = "...8.3.2.";
    char s8[] = "........6";
    char s9[] = "...2759..";
    char* board[] = {s1, s2, s3, s4, s5, s6, s7,s8, s9};

    solveSudoku(board, 9, 9);
    return 0;
}

