#include <stdio.h>

// 函数指针

int Add(int x, int y)
{
    return x + y;
}
int Sub(int x, int y)
{
    return x - y;
}
int Mul(int x, int y)
{
    return x * y;
}
int Div(int x, int y)
{
    return x  / y;
}

void menu()
{
    printf("*************************\n");
    printf("**** 1. Add  2. Sub *****\n");
    printf("**** 3. Mul  4. Div *****\n");
    printf("**** 0. exit        *****\n");
    printf("*************************\n");
}

int main()
{
    int input = 0;
    int x = 0;
    int y = 0;
    int ret = 0;

    // 函数指针数组
    int (*pfArr[]) (int, int) = {0, Add, Sub, Mul, Div};
    do
    {
        menu();
        printf("请选择：>\n");
        scanf("%d", &input);
        if (input == 0)
        {
            printf("退出计算器\n");
        }
        else if (input >= 1 && input <= 4)
        {
            printf("请输入2个操作数:>\n");
            scanf("%d%d", &x, &y);
            ret = pfArr[input](x, y);
            printf("ret = %d\n", ret);
        }
        else
        {
            printf("选择错误\n");
        }
    }
    while (input);
    return 0;
}