/**
 * @file ans.c
 * @brief
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with
 * the character '.'.
 *
 * A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 *
 * @version
 * @date 2015-05-21 09:21
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
    if (board == NULL || *board == NULL)
        return false;
    if (boardRowSize % 3 != 0 || boardColSize % 3 != 0)
        return false;

    for (int y = 0; y < boardRowSize; ++y)
    {
        int dic[10] = {0};
        for (int x = 0; x < boardColSize; ++x)
        {
            char c = board[y][x];
            if (c == '.')
                continue;
            dic[c - '0']--;
            if (dic[c - '0'] < -1)
                return false;
        }
    }

    for (int x = 0; x < boardColSize; ++x)
    {
        int dic[10] = {0};
        for (int y = 0; y < boardRowSize; ++y)
        {
            char c = board[y][x];
            if (c == '.')
                continue;
            dic[c - '0']--;
            if (dic[c - '0'] < -1)
                return false;
        }
    }

    for (int y = 0; y < boardRowSize; y += 3)
        for (int x = 0; x < boardColSize; x += 3)
        {
            int dic[10] = {0};
            for (int j = x; j < x + 3; ++j)
                for (int i = y; i < y + 3; ++i)
                {
                    char c = board[i][j];
                    if (c == '.')
                        continue;
                    dic[c - '0']--;
                    if (dic[c - '0'] < -1)
                        return false;
                }
        }

    return true;
}

int main(int argc, char *argv[])
{
    char* board[9] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};

    printf("%d\n", isValidSudoku(board, 9, 9));
    return 0;
}
