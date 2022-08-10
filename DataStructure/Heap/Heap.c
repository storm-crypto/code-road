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

// 大根堆
void AdjustUp(int* a, int child)
{
    int parent = (child - 1) / 2;

    while (child > 0)
    {
        if (a[parent] < a[child])
        {
            Swap(&a[parent], &a[child]);
            child = parent;
            parent = (parent - 1) / 2;
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

void HeapDestroy(HP* php)
{
    assert(php);
    free(php->a);
    php->a = NULL;
    php->size = php->capacity = 0;
}
// 插入一个元素
void HeapPush(HP* php, HPDataType x)
{
    // 增容
    if (php->size == php->capacity)
    {
        HPDataType* tmp = (HPDataType*)realloc(php->a, php->capacity*2* sizeof(HPDataType));
        if (tmp == NULL)
        {
            printf("realloc failed\n");
            exit(-1);
        }

        php->a = tmp;
        php->capacity *= 2;
    }
    php->a[php->size-1] = x;

    // 向上调整
    AdjustUp(php->a, php->size-1);
}
// 删除堆顶元素
void HeadPop(HP* php)
{
    assert(php);
    assert(php->size > 0);

    Swap(&php->a[php->size-1], &php->a[0]);
    // 删掉最后一个这个原堆的数据
    php->size--;

    AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
    assert(php);
    assert(php->size > 0);

    return php->a[0];
}

int HeapSize(HP* php)
{
    assert(php);
    return php->size;
}

bool HeapEmpty(HP* php)
{
    assert(php);

    return php->size == 0;
}

void HeapPrint(HP* php)
{
    for (int i = 0; i < php->size; i++)
    {
        printf("%d ", php->a[i]);
    }
    printf("\n");
}