#include <stdio.h>
#include "game.h"

void menu()
{
    printf("************************\n");
    printf("*******  1. play  ******\n");
    printf("*******  0. exit  ******\n");
    printf("************************\n");
}

void game()
{
    // 扫雷游戏的实现
    char mine[ROWS][COLS] = {0}; // '0'
    char show[ROWS][COLS] = {0}; // '*'
    // 初始化棋盘
    init_board(mine, ROWS, COLS, '0');
    init_board(show, ROWS, COLS, '*');


}

int main() {
    int input = 0;
    do
    {
        menu();
        printf("请输入你的选择:>\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("三子棋游戏\n");
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (input);

    return 0;
}
