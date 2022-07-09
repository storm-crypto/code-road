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

// 玩家下棋
void play_move(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("玩家下棋\n");
    while (1)
    {
        printf("请输入下标：>");
        scanf("%d %d", &x, &y);
        // 判断下标的取值
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            // 下棋
            // 判断这个下标有没有被占用过
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("该坐标被占用，请重新输入\n");
            }
        }
        else
        {
            printf("坐标非法，请重新输入\n");
        }
    }

}

// 电脑下棋
void computer_move(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("电脑下棋：>\n");
    while (1)
    {
        x = rand() % row; // 0 ~2
        y = rand() % col;

        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }

}