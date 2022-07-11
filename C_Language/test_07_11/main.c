#include <stdio.h>

//int main()
//{
//    int a = 3;
//    int b = -5;
//    //int c = a & b; // 按位与
//    //int c = a | b;   // 按位或
//    int c = a ^ b;   // 按位异或
//    printf("%d\n", c);
//
//    return 0;
//}

// 练习：不能创建临时变量，实现两个数的交换
int main()
{
    int a = 3;
    int b = 5;
    printf("a = %d b = %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a = %d b = %d\n",a, b);

    return 0;
}
