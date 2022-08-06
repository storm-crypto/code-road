//
// Created by ��� on 2022-08-06.
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

// ����+����ͷ+��ѭ��
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

// ������Ĳ���
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// ��������posλ�ú������x
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ��������posλ��֮ǰ����x
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x);

#endif//LIST_SLIST_H
