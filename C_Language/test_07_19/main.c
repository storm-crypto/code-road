#include <stdio.h>

//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}

// 写一个函数打印arr数组的内容

// 方法1：形参写成数组的形式
void print1(int p[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

// 方法2:形参写成指针的形式
void print2(int* p, int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

// 方法3：形参写成数组指针的形式
void print3(int (*p)[10], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        // *p相当于数组名，数组名又是首元素的地址，所以*p就是&arr[0]
        printf("%d ", *(*p + i));
    }
    printf("\n");
}

int main()
{

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sz = sizeof (arr) / sizeof (arr[0]);

    print1(arr, sz);
    print2(arr, sz);
    print3(&arr, sz);

    return 0;
}
