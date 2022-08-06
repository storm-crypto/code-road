//
// Created by 旭哥 on 2022-08-05.
//

#include "SeqList.h"


void SeqListInit(SeqList* pq)
{
    assert(pq);

    pq->a = NULL;
    pq->size = pq->capacity = 0;
}

void SeqListDestory(SeqList* pq)
{
    assert(pq);

    free(pq->a);
    pq->a = NULL;
    pq->size = pq->capacity = 0;
}

void SeqListPrint(SeqList* pq)
{
    assert(pq);
    int i = 0;
    for (i = 0; i < pq->size; i++)
    {
        printf("%d ", pq->a[i]);
    }
    printf("\n");
}

// 检查是否需要扩容
void SeqCheckCapacity(SeqList* pq)
{
    // 如果满了,需要增容
    if (pq->size == pq->capacity)
    {
        int newcapacity = pq->capacity == 0? 4:  pq->capacity * 2;
        SeqDataType* newA = realloc(pq->a, sizeof (SeqDataType) * newcapacity);
        if (newA == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        pq->a = newA;
        pq->capacity = newcapacity;
    }
}

void SeqListPushBack(SeqList* pq, SeqDataType x)
{
    assert(pq);

    // 如果满了,需要增容
    SeqCheckCapacity(pq);
    pq->a[pq->size] = x;
    pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType x)
{
    assert(pq);

    SeqCheckCapacity(pq);

    int end = pq->size - 1;

    while (end >= 0)
    {
        pq->a[end + 1] = pq->a[end];
        end--;
    }

    pq->a[0] = x;
    pq->size++;

}

void SeqListPopBack(SeqList* pq)
{
    assert(pq);
    assert(pq->size > 0);

    pq->size--;
}

void SeqListPopFront(SeqList* pq)
{
    assert(pq);
    assert(pq->size > 0);

    int begin = 0;
    while (begin < pq->size - 1)
    {
        pq->a[begin] = pq->a[begin + 1];
        begin++;
    }

    pq->size--;
}

int SeqListFind(SeqList* pq, SeqDataType x)
{
    assert(pq);
    for (int i = 0; i < pq->size; i++)
    {
        if (pq->a[i] == x)
        {
            return i;
        }
    }

    return -1;
}

void SeqListInsert(SeqList* pq, int pos, SeqDataType x)
{
    assert(pq);
    assert(pos >= 0 && pos < pq->size);

    SeqCheckCapacity(pq);

    int end = pq->size - 1;
    while (end >= pos)
    {
        pq->a[end + 1] = pq->a[end];
        end--;
    }

    pq->a[pos] = x;
    pq->size++;
}

void SeqListErase(SeqList* pq, int pos)
{

}