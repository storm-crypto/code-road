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
    // ɨ����Ϸ��ʵ��
    char mine[ROWS][COLS] = {0}; // '0'
    char show[ROWS][COLS] = {0}; // '*'
    // ��ʼ������
    init_board(mine, ROWS, COLS, '0');
    init_board(show, ROWS, COLS, '*');


}

int main() {
    int input = 0;
    do
    {
        menu();
        printf("���������ѡ��:>\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("��������Ϸ\n");
                break;
            case 0:
                printf("�˳���Ϸ\n");
                break;
            default:
                printf("�����������������\n");
                break;
        }
    } while (input);

    return 0;
}
