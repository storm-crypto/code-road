//
// Created by Ðñ¸ç on 2022-08-08.
//

#include "List.h"


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
    phead->next = newnode;
}
