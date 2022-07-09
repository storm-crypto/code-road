//
// Created by 旭哥 on 2022-07-09.
//

#include "game.h"

void init_board(char arr[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            arr[i][j] = set;
        }
    }
}

void show_board(char arr[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}