#include <stdio.h>

// ���������ֵı����Ŀ

// ���������������в�ͬλ�ĸ���
//int cal_diff_bit(int m, int n)
//{
//    int tmp = m ^ n;
//    int count = 0;
//    while (tmp)
//    {
//        tmp = tmp & (tmp - 1);
//        count++;
//    }
//
//    return count;
//}
//
//int main()
//{
//    int m = 0;
//    int n = 0;
//
//    while (scanf("%d%d", &m, &n) == 2)
//    {
//        int ret = cal_diff_bit(m, n);
//        printf("%d\n", ret);
//    }
//
//    return 0;
//}

// ��ӡ���������Ƶ�����λ��ż��λ
//void Printbit(int num)
//{
//    int i = 0;
//
//    for (i = 31; i >= 1; i -= 2)
//    {
//        printf("%d ", (num >> i) & 1);
//    }
//
//    for (i = 30; i >= 0; i -= 2)
//    {
//        printf("%d ", (num >> i) & 1);
//    }
//}

// ͳ�ƶ�������1�ĸ���

// ����һ

//int cout_one_bit(int num)
//{
//    int count = 0;
//
//    while (num)
//    {
//        if (num % 2 == 1)
//            count ++;
//        num /= 2;
//    }
//
//    return count;
//}

// ����3 ���ж��ٸ�1�Ͱ�λ����ٴΣ����ڵ����ֽ��а�λ�룩

int cout_one_bit(int n)
{
    int count = 0;

    while (n)
    {
        n = n &(n - 1);
        count++;
    }

    return count;
}