#include <accctrl.h>
#include <stdio.h>

// ��ϰ��дһ�������ж�һ�����ǲ�������
// 0��ʾ�ǲ�������
// 1��ʾ������
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
//    // ��ӡ100~200֮�������
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

// ��ϰ���ж�һ���ǲ�������
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
//    // ��ӡ1000~2000֮�������
//    for (i = 1000; i <= 2000; i++)
//    {
//        if (is_leap_year(i) == 1)
//        {
//            printf("%d ", i);
//        }
//    }
//}

// ��ϰ��дһ��������ʵ��һ��������������Ķ��ֲ���
// �Ҳ�������-1
// �ҵ����ض�Ӧ��λ��
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
//        printf("�Ҳ���\n");
//    }
//    else
//        printf("�ҵ��ˣ�λ����:%d", ret);
//    return 0;
//}

// ��ϰ��дһ��������ÿ����һ������������ͻὫnum��ֵ+1

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

// ��ʽ����
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

// �ݹ���ϰ������һ������ֵ(unsigned)������˳���ӡ����ÿһλ��
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
//    print(num); // print�������԰�num��ÿһλ����˳���ӡ����
//}

// ��д��������������ʱ���������ַ�������
//int my_strlen(char *str)
//{
//    int count = 0; // ͳ���ַ�����
//    while (*str != '\0')
//    {
//        count++;
//        str++;
//    }
//    return count;
//}
// �ݹ飬û���õ���ʱ����
//int my_strlen(char *str)
//{
//    if (*str != '\0')
//    {
//         return 1 + my_strlen(str+1);
//    }
//    else
//        return 0;
//}
//
//int main()
//{
//    char arr[] = "abcdef";
//    int len = my_strlen(arr);
//
//    printf("%d\n", len);
//    return 0;
//}

// ��n�Ľ׳ˣ��ݹ�д����
//int fac1(int n)
//{
//    if (n <= 1)
//        return 1;
//    else
//        return n * fac1(n - 1);
//}
//int fac(int n)
//{
//    int i = 0;
//    int ret = 1;
//    for (i = 0; i < n; i++)
//    {
//        ret = ret * i;
//    }
//    return ret;
//}
//int main()
//{
//    int n =0;
//    scanf("%d", &n);
//    int ret = fac(n);
//    printf("%d\n", ret);
//    return 0;
//}

// ��ϰ�����n��쳲�������
// �ݹ�ʵ��
//int fib(int n)
//{
//    if (n <= 2)
//        return 1;
//    else
//        return fib(n - 1) + fib(n - 2);
//}
// �����ķ�ʽ
//int fib(int n)
//{
//    int a = 1;
//    int b = 1;
//    int c = 1;
//
//    while (n > 2)
//    {
//        c = a + b;
//        a  = b;
//        b  = c;
//        n--;
//    }
//    return c;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int ret = fib(n);
//    printf("%d\n", ret);
//    return 0;
//}

//  ��ҵ�������ж�����
//int is_prime(int n)
//{
//    int j = 1;
//    for (j = 2; j < n; j++)
//    {
//        if (n % j == 0)
//        {
//           return 0;
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    int i = 0;
//    for (i = 100; i <= 200; i++)
//    {
//        if (is_prime(i) == 1)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}

// �ж�����
//int is_leap_year(int n)
//{
//    if ((n % 4 == 0 && n % 100 != 0)||(n % 400 == 0))
//        return 1;
//    return 0;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    if (is_leap_year(n) == 1)
//        printf("%d������", n);
//    else
//        printf("%d��������",n);
//    return 0;
//}

// ������������

//void swap(int *a, int *b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//
//int main()
//{
//    int a = 10;
//    int b = 20;
//    printf("����ǰ��a = %d, b = %d\n", a, b);
//    swap(&a, &b);
//    printf("������a = %d, b = %d", a, b);
//}

// ��ӡ�˷��ھ�
//void test(int n)
//{
//    int i = 0;
//    for (i = 1; i <= n; i++)
//    {
//        int j = 0;
//        for (j = 1; j <= i; j++)
//        {
//            printf("%d * %d = %2d   ", i, j, i * j);
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    test(n);
//}

//int Fun(int n)
//{
//    if(n==5)
//        return 2;
//    else
//        return 2*Fun(n+1);
//}
//
//int main()
//{
//    int ret = Fun(2);
//    printf("%d\n", ret);
//}

// ��ӡ����ÿһλ��

//void print(int n )
//{
//    if (n > 9)
//    {
//        print(n / 10);
//    }
//    printf("%d ", n % 10);
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    print(n);
//    return 0;
//}