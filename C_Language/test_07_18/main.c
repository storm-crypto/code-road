#include <stdio.h>

//int main()
//{
//    int a, b, c;
//    a = 5;
//    c = ++a;
//    b = ++c, c++, ++a, a++;
//    b += a++ + c;
//    printf("a = %d b = %d c = %d\n:", a, b, c);
//    return 0;
//}

// 求两个数二进制中不同位的个数
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);

    int i = 0;
    int count = 0;
    for (i = 0; i < 32; i++)
    {
        if (((a>>i) & 1) != ((b >> i) & 1))
        {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}