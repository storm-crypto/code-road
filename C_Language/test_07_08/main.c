#include <stdio.h>

//int main() {
//    // 写代码赋值
//    int i = 0;
//    int arr[100] = {0};
//    int sz = sizeof (arr) / sizeof (arr[0]);
//    // 赋值
//    for (i = 0; i < sz; i++)
//    {
//        arr[i] = i + 1;
//    }
//    // 打印
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

// 一维数组在内存中的存储
//int main()
//{
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int i = 0;
//    int sz = sizeof (arr) / sizeof (arr[0]);
//    for (i = 0; i < sz; i++)
//    {
//        printf("&arr[%d] = %p\n", i, &arr[i]);
//    }
//    return 0;
//}

// 二维数组的创建
//int main()
//{
//    int arr[][5] = {{1, 2}, {3, 4}, {5, 6}};
//    int i = 0;
//    for (i = 0; i < 3; i++)
//    {
//        int j = 0;
//        for (j = 0; j < 5; j++)
//        {
//            printf("&arr[%d][%d] = %p \n", i, j, &arr[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

// 数组作为函数的参数，冒泡排序
void bubble_sort(int arr[], int sz)
{
    // 趟数
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 9, 8, 10};
    int sz = sizeof (arr) / sizeof (arr[0]);
    bubble_sort(arr, sz);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}