//
// Created by ��� on 2022-08-10.
//

#include "Heap.h"

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
// ����ѣ���������
void AdjustDown(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        // ѡ�����Һ����д���Ǹ�
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

    // ��������������ָ��a���Ƶ��ѵ�������
    memcpy(php->a, a, sizeof(HPDataType)*n);
    php->size = n;
    php->capacity = n;

    // ����
    for (int i = (php->size - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(php->a, php->size, i);
    }
}
void HeapDestroy(HP* php);
// ����һ��Ԫ��
void HeapPush(HP* php, HPDataType x);
// ɾ���Ѷ�Ԫ��
void HeadPop(HP* php);
HPDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);