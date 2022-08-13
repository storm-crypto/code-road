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

// 找出a数组中，a[left]、a[right]、a[mid]中大小为middle的值
int GetMidIndex(int* a, int left, int right)
{
    int mid = (left + right) >> 1;
    // a[left] a[mid] a[right]
    if (a[left] < a[mid])
    {
        if (a[right] > a[mid])
        {
            return mid;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
            return right;
    }
    else // a[left] > a[mid]
    {
        if (a[right] > a[left])
        {
            return left;
        }
        else if(a[mid] > a[right])
        {
            return mid;
        }
        else
            return right;
    }
}

// 快速排序hoare版本 左右指针法
int PartSort1(int* a, int left, int right)
{
    int midIndex = GetMidIndex(a, left, right);
    // 始终拿左去做key，所以每次都将key放到left的位置
    Swap(&a[left], &a[midIndex]);
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

    return meeti;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
    // 将最左边的元素拿出来，相当于左边有一个坑了
    int key = a[left];
    while (left < right)
    {
        // right先走
        while (left < right && a[right] >= key)
        {
            right--;
        }
        // 将右边的元素放到左边的坑里面，右边就出现了一个坑
        a[left] = a[right];

        // left走
        while (left < right && a[left] <= key)
        {
            left++;
        }
        // 将左边的元素放到右边的坑里面，左边就出现了一个坑
        a[right] = a[left];
    }

    // 最后将key放入坑里面
    a[left] = key;
    // 返回key排好的合适的位置
    return left;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
    // 进行优化：加上三数取中
    int midIndex = GetMidIndex(a, left, right);
    // 始终拿左去做key，所以每次都将key放到left的位置
    Swap(&a[left], &a[midIndex]);

    int keyi = left;
    int prev = left;
    int cur = left + 1;
    while (cur <= right)
    {
        // 找小
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[cur], &a[prev]);
        }

        // 不进去上面的地方就++cur,交换了也要++
        ++cur;
    }

    // 出了循环，最后也要交换一下
    Swap(&a[keyi], &a[prev]);

    // 返回排好序的那个位置
    return prev;
}

// 快排
void QuickSort(int* a, int begin, int end)
{
    // 递归终止条件
    if (begin >= end)
        return;

    // 1.如果这个子区间的数据较多，继续选key单趟，分割子区间分支递归
    // 2.如果这个子区间的数据较少，再去分支递归不太划算，此时我们选择插入排序
    if (end - begin > 10)
    {
        int meeti = PartSort3(a, begin, end);
        // [begin, meeti - 1] meeti [meeti + 1, end]
        QuickSort(a, begin, meeti - 1);
        QuickSort(a, meeti + 1, end);
    }
    else
    {
        InsertSort(a + begin, end - begin + 1);
    }

}

// 快速排序 非递归实现
// 递归 现代编译器优化的很好，性能已经不是大问题了
// 最大的问题：递归太深，程序本身没有问题，但是栈空间不够，导致栈溢出
// 只能改成非递归，改成非递归有两种形式：
// 1、直接改成循环-》斐波那契数列求解
// 2、树非递归和快排非递归等等，只能用Stack存储数据模拟递归过程
void QuickSortNonR(int* a, int begin, int end)
{
    Stack st;
    StackInit(&st);
    StackPush(&st, begin);
    StackPush(&st, end);

    while (!StackEmpty(&st))
    {
        int left, right;
        right = StackTop(&st);
        StackPop(&st);

        left = StackTop(&st);
        StackPop(&st);

        // 进行一次排序
        int keyi = PartSort1(a, left, right);
        // 左子区间
        if (left < keyi - 1)
        {
            StackPush(&st, left);
            StackPush(&st, keyi - 1);
        }
        // 右子区间
        if (keyi + 1 < right)
        {
            StackPush(&st, keyi + 1);
            StackPush(&st, right);
        }
    }

    StackDestory(&st);
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
    if (left >= right)
        return;

    int mid = (left + right) >> 1;
    // 将mid左边和右边通过递归排好序
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);

    // 进行归并
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int i = left; // 将数组存入tmp数组
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
            tmp[i++] = a[begin1++];
        else
            tmp[i++] = a[begin2++];
    }
    // 进行扫尾
    while (begin1 <= end1)
        tmp[i++] = a[begin1++];

    while (begin2 <= end2)
        tmp[i++] = a[begin2++];

    // 将tmp里面的值复制到a数组里面取
    for (int j = left; j <= right; j++)
        a[j] = tmp[j];
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
    // 给临时数组开辟空间
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
}
