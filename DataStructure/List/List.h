//
// Created by 旭哥 on 2022-08-08.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// 定义结构体
typedef int LTDataType;
typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
}ListNode;

void ListPrint(ListNode* phead);
struct ListNode* BuyListNode(LTDataType x);
// 初始化
ListNode* ListInit();
// 因为头节点是不动的，所以不需要传二级指针
void ListPushBack(ListNode* phead, LTDataType x);
void ListPushFront(ListNode* phead, LTDataType x);

void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);


#endif//LIST_LIST_H
