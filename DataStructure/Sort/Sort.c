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

void Swap(int* p, int* q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

// ֱ��ѡ������
void SelectSort(int* a, int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        // ѡ����С�ĺ�����
        int minIndex = left, maxIndex = left;

        for (int i = left; i <= right; i++)
        {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        // ����������ķ��ұߣ�С�ķ����
        Swap(&a[left], &a[minIndex]);
        // ���������
        // ���max��leftλ���ص���max�������ˣ�Ҫ����һ��max��λ��
        if (left == maxIndex)
            maxIndex = minIndex;
        Swap(&a[right], &a[maxIndex]);
        left++;
        right--;
    }
}

// ������
void AdjustDwon(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        // ����ע���ж�һ��Խ����Щ
        if (child + 1 < n && a[child] < a[child + 1])
        {
            child++;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }

}
void HeapSort(int* a, int n)
{
    // ���� �����
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDwon(a, n, i);
    }

    int end = n - 1;
    while (end >= 0)
    {
        Swap(&a[end], &a[0]);
        end--;
        AdjustDwon(a, end, 0);
    }
}

// ð������
void BubbleSort(int* a, int n)
{
//    // ��ʽһ
//    for (int j = 0; j < n; ++j)
//    {
//        for (int i = 1; i < n - j; i++)
//        {
//            if (a[i] < a[i - 1])
//            {
//                Swap(&a[i], &a[i - 1]);
//            }
//        }
//    }

    // ��ʽ����
    // ���Դ�end��λ�ÿ�ʼ������ѭ���Ĵ���
    for (int end = n; end > 0; end--)
    {
        // ����
        int exchang = 0;
        for (int i = 1; i < end; i++)
        {
            if (a[i] < a[i - 1])
            {
                Swap(&a[i], &a[i - 1]);
                exchang = 1;
            }
        }
        // �������һ������֮��û�з���������˵���ź�����
        if (exchang == 0)
        {
            break;
        }
    }
}

// ����
void QuickSort(int* a, int n)
{
    int left = 0, right = n - 1;
    int keyi = left;
    while (left < right)
    {
        // right��С����Ϊѡ��ߵ�ֵΪkey������Ҫright����
        while (left < right && a[right] >= a[keyi])
        {
            right--;
        }
        // left�Ҵ�
        while (left < right && a[left] <= a[keyi])
        {
            left++;
        }
        Swap(&a[left], &a[right]);
    }
    // ��Ϊ�����key = a[left]��key�Ǿֲ��������Ǹı䲻������a��
    int meeti = left;
    Swap(&a[keyi], &a[meeti]);

}
