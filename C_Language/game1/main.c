//
// Created by ��� on 2022-07-08.
//

// ������������߼�
#include <stdio.h>

void menu()
{
    printf("*****************************\n");
    printf("******* 1. play     *********\n");
    printf("******* 0. exit     *********\n");
    printf("*****************************\n");
}

void test()
{
    int input = 0;
    do
    {
        menu();
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("������\n");
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