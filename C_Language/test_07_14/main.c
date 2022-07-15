#include <stdio.h>

// 练习：设计一个小程序来判断当前机器的字节序

//int check_sys()
//{
//    int a = 1;
//    return *(char*)&a;
//}
//
//int main()
//{
//    int ret = check_sys();
//    if (ret == 1)
//    {
//        printf("小端\n");
//    }
//    else
//    {
//        printf("大端\n");
//    }
//
//    return 0;
//}

// 函数栈帧的创建和销毁

int Add(int a, int b)
{
    int z = 0;
    z = a + b;
    return z;
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;

    c = Add(a, b);

    printf("%d\n", c);

    return 0;
}
