#include <stdio.h>

// 测试三子棋的逻辑
#include "game.h"

void menu()
{
    printf("*****************************\n");
    printf("******* 1. play     *********\n");
    printf("******* 0. exit     *********\n");
    printf("*****************************\n");
}


void game()
{
    // 存放下棋的数据
    char board[ROW][COL] = {0};
    // 初始化棋盘为全空格
    InitBoard(board, ROW, COL);
    // 打印棋盘
    DisplayBoard(board, ROW, COL);
    while (1)
    {
        // 玩家下棋
        play_move(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        // 判断输赢

        // 电脑下棋
        computer_move(board, ROW, COL); // 随机下棋
        DisplayBoard(board, ROW, COL);
    }
}

// 什么时候游戏结束
// 玩家赢
// 电脑赢
// 平局
// 继续

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game(); // 游戏的逻辑
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}
