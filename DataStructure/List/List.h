//
// Created by ��� on 2022-08-08.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

// ����ṹ��
typedef int LTDataType;
struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
};

#endif//LIST_LIST_H
