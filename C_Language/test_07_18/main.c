#include <stdio.h>

// ���������ֵı����Ŀ

// ���������������в�ͬλ�ĸ���
int cal_diff_bit(int m, int n)
{
    int tmp = m ^ n;
    int count = 0;
    while (tmp)
    {
        tmp = tmp & (tmp - 1);
        count++;
    }

    return count;
}

int main()
{
    int m = 0;
    int n = 0;

    while (scanf("%d%d", &m, &n) == 2)
    {
        int ret = cal_diff_bit(m, n);
        printf("%d\n", ret);
    }

    return 0;
}
