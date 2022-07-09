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
