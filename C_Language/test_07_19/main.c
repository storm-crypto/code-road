#include <accctrl.h>
#include <math.h>
#include <stdio.h>

//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}

// дһ��������ӡarr���������

// ����1���β�д���������ʽ
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
// ����2:�β�д��ָ�����ʽ
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
// ����3���β�д������ָ�����ʽ
//void print3(int (*p)[10], int sz)
//{
//    int i = 0;
//    for (i = 0; i < sz; i++)
//    {
//        // *p�൱����������������������Ԫ�صĵ�ַ������*p����&arr[0]
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

// ��ӡ��ά����

// ����1���β�д���������ʽ
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
// ����2���β�д������ָ�����ʽ
// �ﵽ�˽�ά��Ч��
//
//void print2(int (*p)[5], int r, int c)
//{
//    int i = 0;
//    for (i = 0; i < r; i ++)
//    {
//        int j = 0;
//        for (j = 0 ; j < c; j++)
//        {
//            // p + i��ָ���i�е�
//            // *(p + i)�൱���õ��˵�i�У�Ҳ���ǵ�i�е�������
//            // ��������ʾ��Ԫ�صĵ�ַ��*(p + i)���Ǳ�ʾ�õ��˵�i�еĵ�ַ
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

// ָ��ĸ����ϰ��Ŀ

// ��ϰ��ʹ��ָ���ӡ��������
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

// ��ϰ���ַ�������

// ��ϰ���������

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

// ��ϰ����ӡˮ�ɻ���

// 1. ȷ������λ��
// 2. ��ȡÿλ�ϵ�����
// 3. �����ж��ǲ���ˮ�ɻ���

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
//        // 2. ��ȡÿһλ��
//        tmp = i;
//        while (tmp)
//        {
//            sum += pow(tmp % 10, count);
//            tmp /= 10;
//        }
//
//        // 3.�ж�
//        if (sum == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}

// ��ϰ����ӡ����
//int main()
//{
//    int i = 0;
//    int line = 0;
//    scanf("%d", &line);
//
//    // ��ӡ�ϰ벿��
//    for (i = 0; i < line; i++)
//    {
//        // ��ӡ�ո�
//        int j = 0;
//        for (j = 0; j < line - 1 - i; j++)
//        {
//            printf(" ");
//        }
//        // ��ӡ*
//        for (j = 0; j < 2 * i + 1; j++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//
//    // ��ӡ�°벿��
//    for (i = 0; i < line - 1; i++)
//    {
//        // ��ӡ�ո�
//        int j = 0;
//        for (j = 0; j <= i; j++)
//        {
//            printf(" ");
//        }
//        // ��ӡ*
//        for (j = 0; j < 2 * (line - i - 1) - 1; j++)
//        {
//            printf("*");
//        }
//    }
//    printf("\n");
//
//    return 0;
//}

int main()
{
    char a[1000] = {0};
    int i=0;
    for(i=0; i<1000; i++)
    {
        a[i] = -1-i;
    }
    printf("%d",strlen(a));
    return 0;
}
