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
int binary_search(int arr[], int k, int sz)
{
    int left = 0;
    int right = sz - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            return left;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = 0;
    sz = sizeof(arr) / sizeof (arr[0]);
    int ret = binary_search(arr, 7, sz);
    if (-1 == ret)
    {
        printf("�Ҳ���\n");
    }
    else
        printf("�ҵ��ˣ�λ����:%d", ret);
    return 0;
}