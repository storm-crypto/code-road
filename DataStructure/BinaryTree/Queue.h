//
// Created by ??? on 2022-08-10.
//

#ifndef STACKQUEUE_QUEUE_H
#define STACKQUEUE_QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

// Ç°ÖÃÉùÃ÷
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
    struct QueueNode* next;
    QDataType data;
}QueueNode;

typedef struct Queue
{
    QueueNode* head; // ????
    QueueNode* tail; // ¦Â???
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
// ????????
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);


#endif//STACKQUEUE_QUEUE_H
