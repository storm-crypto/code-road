#include <stdio.h>

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
