#include <accctrl.h>
#include <stdio.h>
#include <stdlib.h>

// ����ָ��

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
//    // ����ָ������
//    int (*pfArr[]) (int, int) = {0, Add, Sub, Mul, Div};
//    do
//    {
//        menu();
//        printf("��ѡ��>\n");
//        scanf("%d", &input);
//        if (input == 0)
//        {
//            printf("�˳�������\n");
//        }
//        else if (input >= 1 && input <= 4)
//        {
//            printf("������2��������:>\n");
//            scanf("%d%d", &x, &y);
//            ret = pfArr[input](x, y);
//            printf("ret = %d\n", ret);
//        }
//        else
//        {
//            printf("ѡ�����\n");
//        }
//    }
//    while (input);
//    return 0;
//}

//int main()
//{
//    // ����ָ��
//    int* arr2[5];
//    int* (*p2)[5] = &arr2;
//
//    // ����ָ������
//    int (* pfarr[4])(int, int);
//    int (* (*p3)[4])(int, int) = &pfarr;
//
//    return 0;
//}

//// �ص�����
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

// �ص�����

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
//    printf("����������������:>");
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
//        printf("��ѡ��>\n");
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
//                printf("������������������\n");
//                break;
//        }
//    }
//    while (input);
//    return 0;
//}

// ʹ��qsort����

int cmp_int(const void* e1, const void* e2)
{
    return (*(int*) e1 - *(int*)e2);
}

void print_arr(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void test2()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // ����Ϊ����
    int sz = sizeof (arr) / sizeof (arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    print_arr(arr, sz);
}

struct Stu
{
    char name[20];
    int age;
    double score;
};

int cmp_stu_by_age(const void* e1, const void* e2)
{
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->age);
}

// ʹ��qsort����ṹ��
void test3()
{
    struct Stu arr[3] = {{"zhangsan", 20, 55.5}, {"lisi", 20, 28.0}, {"wangwu", 50, 90.0}};
    int sz = sizeof (arr) / sizeof (arr[0]);
    qsort(arr, sz, sizeof (arr[0]), cmp_stu_by_age);
}


int main()
{
    //test2();
    test3();
    return 0;
}