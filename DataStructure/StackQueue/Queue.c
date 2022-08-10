//
// Created by 旭哥 on 2022-08-10.
//

#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
    assert(pq);

    QueueNode* cur = pq;
    while (cur)
    {
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof (QueueNode));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    if (pq->tail == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
void QueuePop(Queue* pq)
{

    assert(pq);
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QueueNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }

}
// 取队头数据
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
