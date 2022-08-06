//
// Created by 旭哥 on 2022-08-06.
//

#ifndef LIST_SLIST_H
#define LIST_SLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef int SLTDataType;

typedef struct SListNode
{
    SLTDataType data;
    struct SListNode* next;
}SLTNode;

// 单向+不带头+不循环
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode* plist, SLTDataType x);
void SListPushFront(SLTNode* plist, SLTDataType x);

void SListPopBack(SLTNode* plist);
void SListPopFront(SLTNode* plist);

#endif//LIST_SLIST_H
