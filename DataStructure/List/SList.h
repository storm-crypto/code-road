//
// Created by 旭哥 on 2022-08-06.
//

#ifndef LIST_SLIST_H
#define LIST_SLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
}SLTNode;

// 单向+不带头+不循环
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

// 单链表的查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// 单链表在pos位置后面插入x
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 单链表在pos位置之前插入x
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x);

#endif//LIST_SLIST_H
