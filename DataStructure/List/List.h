//
// Created by ��� on 2022-08-08.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdlib.h>
#include <stdio.h>

// ����ṹ��
typedef int LTDataType;
typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
}ListNode;

// ��ʼ��
ListNode* ListInit();

#endif//LIST_LIST_H
