//
// Created by 旭哥 on 2022-08-08.
//

#include "List.h"

// 链表打印
void ListPrint(ListNode* phead)
{
    ListNode* cur = phead->next;
    while(cur != phead)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

struct ListNode* BuyListNode(LTDataType x)
{
    ListNode* node = (ListNode*)malloc(sizeof (ListNode));
    node->next = NULL;
    node->prev = NULL;
    node->data = x;
    return node;
}

ListNode* ListInit()
{
    ListNode* phead = BuyListNode(0);
    phead->next = phead;
    phead->prev = phead;

    return phead;
}

void ListPushBack(ListNode* phead, LTDataType x)
{
//    assert(phead);
//
//    ListNode* tail = phead->prev;
//    ListNode* newnode = BuyListNode(x);
//
//    tail->next = newnode;
//    newnode->prev = tail;
//    newnode->next = phead;
//    phead->prev = newnode;
    // 在phead前面插入一个元素就相当于尾插
    ListInsert(phead, x);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
//    assert(phead);
//    ListNode* first = phead->next;
//    ListNode* newnode = BuyListNode(x);
//
//    phead->next = newnode;
//    newnode->prev = newnode;
//    newnode->next = first;
//    first->prev = newnode;
    // 在phead->next前面插入就相当于头插
    ListInsert(phead->next, x);
}

void ListPopBack(ListNode* phead)
{
//    assert(phead);
//    assert(phead->next != phead);
//
//    ListNode* tail = phead->prev;
//    ListNode* tailPrev = tail->prev;
//    free(tail);
//
//    tailPrev->next = phead;
//    phead->prev = tailPrev;
    // 用ListErase改造
    ListErase(phead->prev);
}
void ListPopFront(ListNode* phead)
{
//    assert(phead);
//    assert(phead->next == phead);
//
//    ListNode* first = phead->next;
//    ListNode* second = first->next;
//    free(first);
//
//    phead->next = second;
//    second->prev = phead;

    // // 用ListErase改造
    ListErase(phead->next);

}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
    assert(phead);

    ListNode* cur = phead->next;

    while (cur != phead)
    {
        if (cur->data == x)
            return cur;
        cur = cur->next;
    }

    return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);

    ListNode* prev = pos->prev;
    ListNode* newnode = BuyListNode(x);
    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = pos;
    pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
    assert(pos);

    ListNode* prev = pos->prev;
    ListNode* next = pos->next;

    prev->next = next;
    next->prev = prev;
    free(pos);
}

int ListEmpty(ListNode* phead)
{
    assert(phead);
    return phead->next == phead? 1 : 0;
}

int ListSize(ListNode* phead)
{
    assert(phead);
    int size = 0;
    ListNode* cur = phead->next;
    while (cur != phead)
    {
        size++;
        cur = cur->next;
    }
    return size;
}

void ListDestory(ListNode* phead)
{
    assert(phead);
    ListNode* cur = phead->next;
    while (cur != phead)
    {
        ListNode* next = phead->next;
        free(cur);
        cur = next;
    }

    free(phead);
    phead = NULL;
}
