//
// Created by ��� on 2022-07-08.
//

#include "game.h"
// ��ʼ������
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

// ��ӡ����
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

// ��ӡ����
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//    int i = 0;
//    for (i = 0; i < row; i++)
//    {
//        // ��ӡ����
//        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//        // ��ӡ�ָ���
//        if (i < row - 1)
//            printf("---|---|---\n");
//    }
//}
void DisplayBoard(char board[ROW][COL], int row, int col) {
    int i = 0;
    for (i = 0; i < row; i++) {
        // ��ӡ����
        int j = 0;
        for (j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        // ��ӡ�ָ���
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

// �������
void play_move(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("�������\n");
    while (1)
    {
        printf("�������±꣺>");
        scanf("%d %d", &x, &y);
        // �ж��±��ȡֵ
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            // ����
            // �ж�����±���û�б�ռ�ù�
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("�����걻ռ�ã�����������\n");
            }
        }
        else
        {
            printf("����Ƿ�������������\n");
        }
    }

}

// ��������
void computer_move(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("�������壺>\n");
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