#include <accctrl.h>
#include <stdio.h>
#include <stdlib.h>

// 函数指针

//int Add(int x, int y)
//{
//    return x + y;
//}
//int Sub(int x, int y)
//{
//    return x - y;
//}
//int Mul(int x, int y)
//{
//    return x * y;
//}
//int Div(int x, int y)
//{
//    return x  / y;
//}
//
//void menu()
//{
//    printf("*************************\n");
//    printf("**** 1. Add  2. Sub *****\n");
//    printf("**** 3. Mul  4. Div *****\n");
//    printf("**** 0. exit        *****\n");
//    printf("*************************\n");
//}
//
//int main()
//{
//    int input = 0;
//    int x = 0;
//    int y = 0;
//    int ret = 0;
//
//    // 函数指针数组
//    int (*pfArr[]) (int, int) = {0, Add, Sub, Mul, Div};
//    do
//    {
//        menu();
//        printf("请选择：>\n");
//        scanf("%d", &input);
//        if (input == 0)
//        {
//            printf("退出计算器\n");
//        }
//        else if (input >= 1 && input <= 4)
//        {
//            printf("请输入2个操作数:>\n");
//            scanf("%d%d", &x, &y);
//            ret = pfArr[input](x, y);
//            printf("ret = %d\n", ret);
//        }
//        else
//        {
//            printf("选择错误\n");
//        }
//    }
//    while (input);
//    return 0;
//}

//int main()
//{
//    // 数组指针
//    int* arr2[5];
//    int* (*p2)[5] = &arr2;
//
//    // 函数指针数组
//    int (* pfarr[4])(int, int);
//    int (* (*p3)[4])(int, int) = &pfarr;
//
//    return 0;
//}

//// 回调函数
//void test()
//{
//    printf("hehe\n");
//}
//
//void print_hehe(void (*p)())
//{
//    if (1)
//        p();
//}
//
//int main()
//{
//    print_hehe(test);
//
//    return 0;
//}

// 回调函数

//int Add(int x, int y)
//{
//    return x + y;
//}
//int Sub(int x, int y)
//{
//    return x - y;
//}
//int Mul(int x, int y)
//{
//    return x * y;
//}
//int Div(int x, int y)
//{
//    return x  / y;
//}
//
//void menu()
//{
//    printf("*************************\n");
//    printf("**** 1. Add  2. Sub *****\n");
//    printf("**** 3. Mul  4. Div *****\n");
//    printf("**** 0. exit        *****\n");
//    printf("*************************\n");
//}
//
//void cal(int (*p)(int, int))
//{
//    int x = 0;
//    int y = 0;
//    int ret = 0;
//    printf("请输入两个操作数:>");
//    scanf("%d%d", &x, &y);
//    ret = p(x, y);
//    printf("ret = %d\n", ret);
//}
//
//int main()
//{
//    int input = 0;
//
//    do
//    {
//        menu();
//        printf("请选择：>\n");
//        scanf("%d", &input);
//        switch (input)
//        {
//            case 1:
//                cal(Add);
//                break;
//            case 2:
//                cal(Sub);
//                break;
//            case 3:
//                cal(Mul);
//                break;
//            case 4:
//                cal(Div);
//                break;
//            case 0:
//                break;
//            default:
//                printf("输入有误，请重新输入\n");
//                break;
//        }
//    }
//    while (input);
//    return 0;
//}

// 使用qsort函数

//int cmp_int(const void* e1, const void* e2)
//{
//    return (*(int*) e1 - *(int*)e2);
//}
//
//void print_arr(int arr[], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void test2()
//{
//    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//    // 排序为升序
//    int sz = sizeof (arr) / sizeof (arr[0]);
//    qsort(arr, sz, sizeof(arr[0]), cmp_int);
//    print_arr(arr, sz);
//}
//
//struct Stu
//{
//    char name[20];
//    int age;
//    double score;
//};
//
//int cmp_stu_by_age(const void* e1, const void* e2)
//{
//    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int cmp_stu_by_name(const void* e1, const void* e2)
//{
//    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->age);
//}
//
//// 使用qsort排序结构体
//void test3()
//{
//    struct Stu arr[3] = {{"zhangsan", 20, 55.5}, {"lisi", 20, 28.0}, {"wangwu", 50, 90.0}};
//    int sz = sizeof (arr) / sizeof (arr[0]);
//    qsort(arr, sz, sizeof (arr[0]), cmp_stu_by_age);
//}

// 仿照qsort函数，改写一个通用版本的bubble_sort函数

void print_arr(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cmp_int(const void* e1, const void* e2)
{
    return (*(int*) e1 - *(int*)e2);
}

void Swap(char* buf1, char* buf2, int width)
{
    int i = 0;
    for (i = 0; i < width; i++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}

void bubble_sort(void* base, int num, int width, int (*cmp)(const void* e1, const void* e2))
{
    int i = 0;
    for (i = 0; i < num - 1; i++)
    {
        int j = 0;
        for (j = 0; j < num - i - 1; j++)
        {
            // if (arr[j] > arr[j + 1])
            if (cmp((char*)base + j * width, (char*)base + (j + 1) * width))
            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
                  // 交换函数
                  Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
            }
        }
    }
}

void test2()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof (arr) / sizeof (arr[0]);
    bubble_sort(arr, sz, sizeof (arr[0]), cmp_int);
    print_arr(arr, sz);
}


int main()
{
    test2();
    return 0;
}