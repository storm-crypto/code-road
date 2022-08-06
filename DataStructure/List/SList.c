//
// Created by 旭哥 on 2022-08-06.
//

#include "SList.h"

void SListPrint(SLTNode* plist)
{
    SLTNode* cur = plist;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// 创建一个结点
SLTNode* BuySLTNode(SLTDataType x)
{
    SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
    node->data = x;
    node->next = NULL;
    return node;
}

void SListPushBack(SLTNode** pplist, SLTDataType x)
{
    SLTNode * newNode = BuySLTNode(x);
    // 要加这一步判断一下，如果不加这一步就会导致空指针异常
    if (*pplist == NULL)
    {
        *pplist = newNode;
    }
    else
    {
        SLTNode* tail = *pplist;
        // 找最后一个结点的地址，用这个条件刚好让tail指向最后一个结点的地址
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }

}

void SListPushFront(SLTNode** pplist, SLTDataType x)
{
    SLTNode* newNode = BuySLTNode(x);
    newNode->next = *pplist;
    *pplist = newNode;
}

void SListPopBack(SLTNode** pplist)
{
    // 1. 没有节点
    // 2. 一个节点
    // 3. 多个节点
    if (*pplist == NULL)
    {
        return;
    }
    else if ((*pplist)->next == NULL)
    {
        free(*pplist);
        *pplist = NULL;
    }
    else
    {
        SLTNode* pre = NULL;
        SLTNode* tail = *pplist;
        while (tail->next != NULL)
        {
            pre = tail;
            tail = tail->next;
        }

        free(tail);
        tail = NULL;

        pre->next = NULL;
    }

}

void SListPopFront(SLTNode** pplist)
{
    if (*pplist == NULL)
    {
        return;
    }
    else
    {
        SLTNode* next = (*pplist)->next;
        free(*pplist);

        *pplist = next;
    }
}

// 链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
    SLTNode* cur = plist;
    while (cur != NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}