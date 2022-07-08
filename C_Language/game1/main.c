//
// Created by 旭哥 on 2022-07-08.
//

// 测试三子棋的逻辑
#include <stdio.h>

void menu()
{
    printf("*****************************\n");
    printf("******* 1. play     *********\n");
    printf("******* 0. exit     *********\n");
    printf("*****************************\n");
}

void

void game()
{
     // 存放下棋的数据
     char board[3][3] = {0};
     // 初始化棋盘为全空格
     InitBoard(board, 3, 3); // 初始化数组
}

void test()
{
    int input = 0;
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