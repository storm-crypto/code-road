//
// Created by 旭哥 on 2022-08-08.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdlib.h>
#include <stdio.h>

// 定义结构体
typedef int LTDataType;
typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
}ListNode;

// 初始化
ListNode* ListInit();

#endif//LIST_LIST_H
