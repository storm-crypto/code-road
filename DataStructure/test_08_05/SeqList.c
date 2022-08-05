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

void SeqListPushBack(SeqList* pq, SeqDataType x)
{
    assert(pq);

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
    pq->a[pq->size] = x;
    pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType x)
{
    assert(pq);
}
