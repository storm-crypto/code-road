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
int is_leap_year(int n)
{
    if (((n % 4 == 0)&&(n % 100 != 0))||(n % 400 == 0))
        return 1;
    else
        return 0;
}
int main()
{
    int i = 0;
    // ��ӡ1000~2000֮�������
    for (i = 1000; i <= 2000; i++)
    {
        if (is_leap_year(i) == 1)
        {
            printf("%d ", i);
        }
    }
}