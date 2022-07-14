#include <stdio.h>

// 练习：设计一个小程序来判断当前机器的字节序

int check_sys()
{
    int a = 1;
    return *(char*)&a;
}

int main()
{
    int ret = check_sys();
    if (ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }

    return 0;
}
