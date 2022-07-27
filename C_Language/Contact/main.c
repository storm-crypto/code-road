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
        printf("请选择：>");
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
                printf("退出通讯录\n");
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
