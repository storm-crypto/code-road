#include <stdio.h>

// ������������߼�
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
    // ������������
    char board[ROW][COL] = {0};
    // ��ʼ������Ϊȫ�ո�
    InitBoard(board, ROW, COL);
    // ��ӡ����
    DisplayBoard(board, ROW, COL);
    while (1)
    {
        // �������
        play_move(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        // �ж���Ӯ

        // ��������
        computer_move(board, ROW, COL); // �������
        DisplayBoard(board, ROW, COL);
    }
}

// ʲôʱ����Ϸ����
// ���Ӯ
// ����Ӯ
// ƽ��
// ����

void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game(); // ��Ϸ���߼�
                break;
            case 0:
                printf("�˳���Ϸ\n");
                break;
            default:
                printf("ѡ�����\n");
                break;
        }
    } while (input);
}

int main()
{
    test();
    return 0;
}
