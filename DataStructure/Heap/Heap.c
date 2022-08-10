//
// Created by 旭哥 on 2022-08-10.
//

#include "Heap.h"

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
// 建大堆，升序排序
void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        // 选出左右孩子中大的那个
        if (child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }

        if (a[child] > a[parent])
        {
            Swap(&a[parent], &a[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}


void HeapInit(HP* php ,HPDataType* a, int n)
{
    assert(php);
    php->a = (HPDataType*)malloc(sizeof (HPDataType) * n);
    if (php->a == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    // 将传进来的数组指针a复制到堆的数组中
    memcpy(php->a, a, sizeof(HPDataType)*n);
    php->size = n;
    php->capacity = n;

    // 建堆
    for (int i = (php->size - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(php->a, php->size, i);
    }
}
void HeapDestroy(HP* php);
// 插入一个元素
void HeapPush(HP* php, HPDataType x);
// 删除堆顶元素
void HeadPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);