#include <stdio.h>
#include <string.h>

namespace bit
{
    int scanf = 10;
    int strlen = 20;
}

int main()
{
    // 打印库函数中的scanf和strlen的地址
    // 没有指定默认访问局部或者全局的
    printf("%x\n", scanf);
    printf("%x\n", strlen);

    // 指定访问bit这个命名空间里面的scanf和strlen
    printf("%x\n", bit::scanf);
    printf("%x\n", bit::strlen);

    return 0;
}
