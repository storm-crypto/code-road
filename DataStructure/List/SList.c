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

// 单链表在pos位置后面插入x
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
    assert(pos);

    SLTNode* newNode = BuySLTNode(x);
    newNode->next = pos->next;
    pos->next = newNode;
}

// 单链表在pos位置之前插入x(很麻烦，不适合单链表)
// 需要找到pos之前的位置，所以需要plist
// 可能需要改变plist的地址，所以参数要是二级指针
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
    assert(pos);

    SLTNode* newNode = BuySLTNode(x);

    // 特殊情况
    if (pos == *pplist) // 头插
    {
        newNode->next = pos;
        *pplist = newNode;
    }
    else
    {
        SLTNode* prev = NULL;
        SLTNode* cur = *pplist;
        while (cur != pos)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = newNode;
        newNode->next = pos;
    }

}

void SListEraseAfter(SLTNode* pos)
{
    assert(pos);
    if (pos->next == NULL)
    {
        return;
    }
    else
    {
        SLTNode* next = pos->next;
        pos->next = next->next;
        free(next);
        next = NULL;

    }
}

void SListEraseCur(SLTNode** pplist, SLTNode* pos)
{
    assert(pos);

    // 自己就是第一个，相当于是头删
    if (*pplist == pos)
    {
        SListPopFront(pplist);
    }

    // 常规情况，需要找到pos位置的前一个位置
    else
    {
        SLTNode* prev = NULL;
        SLTNode* cur = *pplist;
        while (cur != pos)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        free(cur);
        cur = NULL;
    }

}