/**
 * @file ans.c
 * @brief
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where
 * "adjacent" cells are those horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 * For example,
 *  Given board =
 *  [
 *    ["ABCE"],
 *    ["SFCS"],
 *    ["ADEE"]
 *  ]
 *
 *  word = "ABCCED", -> returns true,
 *  word = "SEE", -> returns true,
 *  word = "ABCB", -> returns false.
 *
 * @version
 * @date 2015-06-13 20:30
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

bool check(char** board, int boardRowSize, int boardColSize, int i, int j, char* word, int wordIdx)
{
    if (board[i][j] == word[wordIdx])
    {
        if (wordIdx == (int)strlen(word) - 1)
            return true;
        char tmp = board[i][j];
        board[i][j] = '\0';

        if (i > 0)
        {
            if (check(board, boardRowSize, boardColSize, i - 1, j, word, wordIdx + 1))
            {
                board[i][j] = tmp;
                return true;
            }
        }

        if (i < boardRowSize - 1)
        {
            if (check(board, boardRowSize, boardColSize, i + 1, j, word, wordIdx + 1))
            {
                board[i][j] = tmp;
                return true;
            }
        }

        if (j > 0)
        {
            if (check(board, boardRowSize, boardColSize, i, j - 1, word, wordIdx + 1))
            {
                board[i][j] = tmp;
                return true;
            }
        }

        if (j < boardColSize - 1)
        {
            if (check(board, boardRowSize, boardColSize, i, j + 1, word, wordIdx + 1))
            {
                board[i][j] = tmp;
                return true;
            }
        }

        board[i][j] = tmp;
    }

    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word)
{
    if (board == NULL || word == NULL || (int)strlen(word) == 0 || (int)strlen(word) > boardRowSize * boardColSize)
        return false;

    for (int i = 0; i < boardRowSize; i++)
    {
        for (int j = 0; j < boardColSize; j++)
        {
            if (check(board, boardRowSize, boardColSize, i, j, word, 0))
                return true;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    char s1[] = "ABCE";
    char s2[] = "SFCS";
    char s3[] = "ADEE";
    char* board[] = {s1, s2, s3};

    char* word1 = "ABCCED";
    char* word2 = "SEE";
    char* word3 = "ABCB";

    printf("%d\n", exist(board, 3, 4, word1));
    printf("%d\n", exist(board, 3, 4, word2));
    printf("%d\n", exist(board, 3, 4, word3));

    return 0;
}

