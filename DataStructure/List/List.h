//
// Created by ��� on 2022-08-08.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// ����ṹ��
typedef int LTDataType;
typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
}ListNode;

void ListPrint(ListNode* phead);
struct ListNode* BuyListNode(LTDataType x);
// ��ʼ��
ListNode* ListInit();
// ��Ϊͷ�ڵ��ǲ����ģ����Բ���Ҫ������ָ��
void ListPushBack(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);

void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);


#endif//LIST_LIST_H
