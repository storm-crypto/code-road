#include <stdio.h>

// 操作符部分的变成题目

// 求两个数二进制中不同位的个数
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
