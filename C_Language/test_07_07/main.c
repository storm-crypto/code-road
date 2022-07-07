#include <stdio.h>

// 练习：写一个函数判断一个数是不是素数
// 0表示是不是素数
// 1表示是素数
//int is_prime(int n)
//{
//    int j = 0;
//    for (j = 2; j < n; j++)
//    {
//        if (n % j == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    int i = 0;
//    // 打印100~200之间的素数
//    for (i = 100; i <= 200; i++)
//    {
//        if (is_prime(i) == 1)
//        {
//            printf("%d ", i);
//        }
//    }
//
//    return 0;
//}

// 练习：判断一年是不是闰年
int is_leap_year(int n)
{
    if (((n % 4 == 0)&&(n % 100 != 0))||(n % 400 == 0))
        return 1;
    else
        return 0;
}
int main()
{
    int i = 0;
    // 打印1000~2000之间的闰年
    for (i = 1000; i <= 2000; i++)
    {
        if (is_leap_year(i) == 1)
        {
            printf("%d ", i);
        }
    }
}