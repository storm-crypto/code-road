//
// Created by –Ò∏Á on 2022-07-08.
//

#include "game.h"
#include "game.h"
// ≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// ¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}