//
// Created by 旭哥 on 2022-07-08.
//

#include "game.h"
// 初始化棋盘
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

// 打印棋盘
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        int j = 0;
//        for (j = 0; j < col; j++)
//        {
//            printf("%c", board[i][j]);
//        }
//        printf("\n");
//    }
//}

// 打印棋盘
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        // 打印数据
//        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//        // 打印分割行
//        if (i < row - 1)
//            printf("---|---|---\n");
//    }
//}
void DisplayBoard(char board[ROW][COL], int row, int col) {
    int i = 0;
    for (i = 0; i < row; i++) {
        // 打印数据
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        // 打印分割行
        if (i < row - 1)
        {
            for (j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
}