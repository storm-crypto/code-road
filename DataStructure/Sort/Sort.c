//
// Created by 旭哥 on 2022-08-12.
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

// 插入排序
void InsertSort(int* a, int n)
{
    // 多趟，因为end = n - 2的时候就排序结束了
    for (int i = 0; i < n - 1; i++)
    {
        // 把tmp插入到0~end的连续区间中
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
        // 特殊情况，当end = -1的时候，下面这个式子同样适合
        // 所以干脆直接else那里break掉，如果找到合适的位置就
        // 将tmp填入这位置里面
        a[end + 1] = tmp;
    }
}
// 希尔排序
void ShellSort(int* a, int n)
{
    int gap;
    int end;
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
