//
// Created by ��� on 2022-08-12.
//

#include "Sort.h"

void Print(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

// ��������
void InsertSort(int* a, int n)
{
    // ���ˣ���Ϊend = n - 2��ʱ������������
    for (int i = 0; i < n - 1; i++)
    {
        // ��tmp���뵽0~end������������
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        // �����������end = -1��ʱ���������ʽ��ͬ���ʺ�
        // ���Ըɴ�ֱ��else����break��������ҵ����ʵ�λ�þ�
        // ��tmp������λ������
        a[end + 1] = tmp;
    }
}
// ϣ������
void ShellSort(int* a, int n)
{
    // gap > 1��ʱ��Ԥ����
    // gap == 1��ʱ����ֱ�Ӳ�������
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        // �������е�����Ԫ�ؽ���һ��Ԥ����
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }


}
