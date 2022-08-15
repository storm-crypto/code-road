#include <stdio.h>
#include <string.h>

namespace bit
{
    int scanf = 10;
    int strlen = 20;

    // 嵌套定义命名空间
    namespace N3
    {
        int c;
        int d;
        int Sub(int left, int right)
        {
            return left - right;
        }
    }
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

    // 嵌套定义的命名空间的使用
    bit::N3::Sub(10, 3);

    return 0;
}
