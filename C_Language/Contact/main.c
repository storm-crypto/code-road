#include <stdio.h>

void menu()
{
    printf("*****************************\n");
    printf("**** 1.add      2.del    ****\n");
    printf("**** 3. search  4.modify ****\n");
    printf("**** 5.sort     0.exit   ****\n");
    printf("*****************************\n");
}


void test()
{
    int input = 0;
    do
    {
        menu();
        printf("��ѡ��>");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                printf("�˳�ͨѶ¼\n");
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
