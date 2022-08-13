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
    // gap > 1的时候，预排序
    // gap == 1的时候，是直接插入排序
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        // 对数组中的所有元素进行一次预排序
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

// 直接选择排序
void SelectSort(int* a, int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        // 选出最小的和最大的
        int minIndex = left, maxIndex = left;

        for (int i = left; i <= right; i++)
        {
            if (a[i] < a[minIndex])
                minIndex = i;
            if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        // 交换：将大的放右边，小的放左边
        Swap(&a[left], &a[minIndex]);
        // 特殊情况：
        // 如果max和left位置重叠，max被换走了，要修正一下max的位置
        if (left == maxIndex)
            maxIndex = minIndex;
        Swap(&a[right], &a[maxIndex]);
        left++;
        right--;
    }
}

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        // 这里注意判断一下越界那些
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
    // 升序 建大堆
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

// 冒泡排序
void BubbleSort(int* a, int n)
{
//    // 方式一
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

    // 方式二：
    // 可以从end的位置开始来考虑循环的次数
    for (int end = n; end > 0; end--)
    {
        // 单趟
        int exchang = 0;
        for (int i = 1; i < end; i++)
        {
            if (a[i] < a[i - 1])
            {
                Swap(&a[i], &a[i - 1]);
                exchang = 1;
            }
        }
        // 如果经过一次排序之后，没有发生交换，说明排好序了
        if (exchang == 0)
        {
            break;
        }
    }
}

// 快排
void QuickSort(int* a, int n)
{
    int left = 0, right = n - 1;
    int keyi = left;
    while (left < right)
    {
        // right找小，因为选左边的值为key，所以要right先走
        while (left < right && a[right] >= a[keyi])
        {
            right--;
        }
        // left找大
        while (left < right && a[left] <= a[keyi])
        {
            left++;
        }
        Swap(&a[left], &a[right]);
    }
    // 因为如果是key = a[left]，key是局部变量，是改变不了数组a的
    int meeti = left;
    Swap(&a[keyi], &a[meeti]);

}
