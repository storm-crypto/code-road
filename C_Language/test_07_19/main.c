#include <stdio.h>

//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}

// дһ��������ӡarr���������

// ����1���β�д���������ʽ
void print1(int p[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

// ����2:�β�д��ָ�����ʽ
void print2(int* p, int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

// ����3���β�д������ָ�����ʽ
void print3(int (*p)[10], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        // *p�൱����������������������Ԫ�صĵ�ַ������*p����&arr[0]
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
