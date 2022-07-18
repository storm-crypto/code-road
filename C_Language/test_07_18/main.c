#include <stdio.h>

// 操作符部分的变成题目

// 求两个数二进制中不同位的个数
//int cal_diff_bit(int m, int n)
//{
//    int tmp = m ^ n;
//    int count = 0;
//    while (tmp)
//    {
//        tmp = tmp & (tmp - 1);
//        count++;
//    }
//
//    return count;
//}
//
//int main()
//{
//    int m = 0;
//    int n = 0;
//
//    while (scanf("%d%d", &m, &n) == 2)
//    {
//        int ret = cal_diff_bit(m, n);
//        printf("%d\n", ret);
//    }
//
//    return 0;
//}

// 打印整数二进制的奇数位和偶数位
//void Printbit(int num)
//{
//    int i = 0;
//
//    for (i = 31; i >= 1; i -= 2)
//    {
//        printf("%d ", (num >> i) & 1);
//    }
//
//    for (i = 30; i >= 0; i -= 2)
//    {
//        printf("%d ", (num >> i) & 1);
//    }
//}

// 统计二进制中1的个数

// 方法一

//int cout_one_bit(int num)
//{
//    int count = 0;
//
//    while (num)
//    {
//        if (num % 2 == 1)
//            count ++;
//        num /= 2;
//    }
//
//    return count;
//}

// 方法3 ：有多少个1就按位与多少次（相邻的数字进行按位与）

//int cout_one_bit(int n)
//{
//    int count = 0;
//
//    while (n)
//    {
//        n = n &(n - 1);
//        count++;
//    }
//
//    return count;
//}

// 交换两个变量（不创建临时变量）

int main()
{
    int a = 0;
    int b = 0;

    scanf("%d%d", &a, &b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("交换后：a = %d, b = %d", a, b);

    return 0;
}