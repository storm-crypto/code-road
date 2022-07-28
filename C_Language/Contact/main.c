#include <stdio.h>
#include "contact.h"



void menu()
{
    printf("*****************************\n");
    printf("**** 1.add      2.del    ****\n");
    printf("**** 3. search  4.modify ****\n");
    printf("**** 5.sort     6.print  ****\n");
    printf("**** 0.exit              ****\n");
    printf("*****************************\n");
}


void test()
{
    int input = 0;
    // 创建通讯录
    Contact con; // 通讯录

    do
    {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        switch (input)
        {
            case ADD:

                break;
            case DEL:
                break;
            case SEARCH:
                break;
            case MODIFY:
                break;
            case SORT:
                break;
            case PRINT:
                break;
            case EXIT:
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
