#include <accctrl.h>
#include <math.h>
#include <stdio.h>

//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}

// 写一个函数打印arr数组的内容

// 方法1：形参写成数组的形式
//void print1(int p[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", p[i]);
//    }
//    printf("\n");
//}
//
// 方法2:形参写成指针的形式
//void print2(int* p, int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(p + i));
//    }
//    printf("\n");
//}
//
// 方法3：形参写成数组指针的形式
//void print3(int (*p)[10], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        // *p相当于数组名，数组名又是首元素的地址，所以*p就是&arr[0]
//        printf("%d ", *(*p + i));
//    }
//    printf("\n");
//}
//
//int main()
//{
//
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//    int sz = sizeof (arr) / sizeof (arr[0]);
//
//    print1(arr, sz);
//    print2(arr, sz);
//    print3(&arr, sz);
//
//    return 0;
//}

// 打印二维数组

// 方法1：形参写成数组的形式
//void print1(int p[3][5], int r, int c)
//{
//    int i = 0;
//    for (i = 0; i < r; i ++)
//    {
//        int j = 0;
//        for (j = 0 ; j < c; j++)
//        {
//            printf("%d ", p[i][j]);
//        }
//        printf("\n");
//    }
//}
//
// 方法2：形参写成数组指针的形式
// 达到了降维的效果
//
//void print2(int (*p)[5], int r, int c)
//{
//    int i = 0;
//    for (i = 0; i < r; i ++)
//    {
//        int j = 0;
//        for (j = 0 ; j < c; j++)
//        {
//            // p + i是指向第i行的
//            // *(p + i)相当于拿到了第i行，也就是第i行的数组名
//            // 数组名表示首元素的地址，*(p + i)就是表示拿到了第i行的地址
//            printf("%d ", *(*(p + i) + j));
//            // printf("%d ", p[i][j]);
//        }
//        printf("\n");
//    }
//
//}
//
//int main()
//{
//    int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
//
//    print1(arr, 3, 5);
//    print2(arr, 3, 5);
//
//    return 0;
//}

// 指针的概念，练习题目

// 练习：使用指针打印数组内容
//void print1(int* arr, int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(arr + i));
//    }
//}
//
//int main()
//{
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int sz = sizeof (arr) / sizeof (arr[0]);
//
//    print1(arr, sz);
//}

// 练习：字符串逆序

// 练习：计算求和

//int main()
//{
//    int i = 0;
//    int sum = 0;
//    int tmp = 0;
//    int a = 0;
//    int n = 0;
//
//    scanf("%d%d", &a, &n);
//
//    for (i = 0; i < n; i++)
//    {
//        tmp = tmp * 10 + a;
//        sum += tmp;
//    }
//
//    printf("%d\n", sum);
//    return 0;
//}

// 练习：打印水仙花数

// 1. 确定数的位数
// 2. 获取每位上的数字
// 3. 进行判断是不是水仙花数

//int main()
//{
//    int i = 0;
//    for (i = 0; i < 100000; i++)
//    {
//        int count = 1;
//        int tmp = i;
//        int sum = 0;
//
//        // 1.
//        while (tmp / 10)
//        {
//            count++;
//            tmp /= 10;
//        }
//
//        // 2. 获取每一位数
//        tmp = i;
//        while (tmp)
//        {
//            sum += pow(tmp % 10, count);
//            tmp /= 10;
//        }
//
//        // 3.判断
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}

// 练习：打印菱形
int main()
{
    int i = 0;
    int line = 0;
    scanf("%d", &line);

    // 打印上半部分
    for (i = 0; i < line; i++)
    {
        // 打印空格
        int j = 0;
        for (j = 0; j < line - 1 - i; j++)
        {
            printf(" ");
        }
        // 打印*
        for (j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // 打印下半部分
    for (i = 0; i < line - 1; i++)
    {
        // 打印空格
        int j = 0;
        for (j = 0; j <= i; j++)
        {
            printf(" ");
        }
        // 打印*
        for (j = 0; j < 2 * (line - i - 1) - 1; j++)
        {
            printf("*");
        }
    }
    printf("\n");

    return 0;
}

//int main()
//{
//    char a[1000] = {0};
//    int i=0;
//    for(i=0; i<1000; i++)
//    {
//        a[i] = -1-i;
//    }
//    printf("%d",strlen(a));
//    return 0;
//}



// 结构体的练习题

// 喝汽水问题
