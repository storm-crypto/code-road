#include <accctrl.h>
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
//int is_leap_year(int n)
//{
//    if (((n % 4 == 0)&&(n % 100 != 0))||(n % 400 == 0))
//        return 1;
//    else
//        return 0;
//}
//int main()
//{
//    int i = 0;
//    // 打印1000~2000之间的闰年
//    for (i = 1000; i <= 2000; i++)
//    {
//        if (is_leap_year(i) == 1)
//        {
//            printf("%d ", i);
//        }
//    }
//}

// 练习：写一个函数，实现一个整型有序数组的二分查找
// 找不到返回-1
// 找到返回对应的位置
//int binary_search(int arr[], int k, int sz)
//{
//    int left = 0;
//    int right = sz - 1;
//
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] < k)
//        {
//            left = mid + 1;
//        }
//        else if (arr[mid] > k)
//        {
//            right = mid - 1;
//        }
//        else
//        {
//            return left;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int sz = 0;
//    sz = sizeof(arr) / sizeof (arr[0]);
//    int ret = binary_search(arr, 7, sz);
//    if (-1 == ret)
//    {
//        printf("找不到\n");
//    }
//    else
//        printf("找到了，位置是:%d", ret);
//    return 0;
//}

// 练习：写一个函数，每调用一次这个函数，就会将num的值+1

//void test(int *p)
//{
//    *p = *p + 1;
//}
//
//int main()
//{
//    int num = 0;
//    test(&num);
//    printf("%d\n",num);
//    return 0;
//}

// 链式访问
//int main()
//{
//    // printf("len = %d",  strlen("absd"));
//
//    printf("%d", printf("%d", printf("%d", 43)));
//}


//#include "add.h"
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    int sum = Add(a, b);
//    printf("%d\n", sum);
//    return 0;
//}

// 递归练习：接受一个整型值(unsigned)，按照顺序打印它的每一位。
//void print(int n)
//{
//    if (n > 9)
//    {
//        print(n / 10);
//    }
//    printf("%d ", n % 10);
//}
//int main()
//{
//    unsigned int num = 0;
//    scanf("%d", &num);
//    print(num); // print函数可以把num的每一位按照顺序打印出来
//}

// 编写函数不允许创建临时变量，求字符串长度
int my_strlen(char *str)
{
    int count = 0; // 统计字符个数
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char arr[] = "abcdef";
    int len = my_strlen(arr);

    printf("%d\n", len);
    return 0;
}
