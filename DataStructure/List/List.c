//
// Created by Ðñ¸ç on 2022-08-08.
//

#include "List.h"

// Á´±í´òÓ¡
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
    assert(phead);

    ListNode* tail = phead->prev;
    ListNode* newnode = BuyListNode(x);

    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = phead;
    phead->prev = newnode;
}

void ListPushFront(ListNode* phead, LTDataType x)
{
    assert(phead);
    ListNode* first = phead->next;
    ListNode* newnode = BuyListNode(x);

    phead->next = newnode;
    newnode->prev = newnode;
    newnode->next = first;
    first->prev = newnode;
}

void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
