//
// Created by 旭哥 on 2022-08-08.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

// 定义结构体
typedef int LTDataType;
struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
};

#endif//LIST_LIST_H
