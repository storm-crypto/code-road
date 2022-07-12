#include <stdio.h>

//int* test()
//{
//    int a = 10;
//    return &a;
//}
//
//int main() {
//   int *p = test();
//   *p = 100;
//    return 0;
//}

// 用指针实现my_strlen
//int my_strlen(char* str)
//{
//    char* start = str;
//    while (*str)
//    {
//        str++;
//    }
//    return str - start;
//}
//
//int main()
//{
//    char arr[] = "abcdef";
//    int len = my_strlen(arr);
//    printf("%d\n", len);
//
//    return 0;
//}

//int main()
//{
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int *p = arr;
//    int sz = sizeof (arr) / sizeof (arr[0]);
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", *(p + i));
//    }
//
//    return 0;
//}

//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    printf("%p\n", arr);
//    printf("%p\n", arr + 1);
//
//    printf("%p\n", &arr[0]);
//    printf("%p\n", &arr[0] + 1);
//
//    printf("%p\n", &arr);
//    printf("%p\n", &arr + 1);
//
//    return 0;
//}

// 指针数组

int main()
{
    int data1[] = {1, 2, 3, 4, 5};
    int data2[] = {2, 3, 4, 5, 6};
    int data3[] = {3, 4, 5, 6, 7};

    int* arr[3] = {data1, data2, data3};
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 5; j++)
        {
            printf("%d ", *(arr[i] + j));
        }
        printf("\n");
    }
    return 0;
}
