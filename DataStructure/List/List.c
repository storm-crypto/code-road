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

void ListPopBack(ListNode* phead)
{
    assert(phead);
    assert(phead->next != phead);

    ListNode* tail = phead->prev;
    ListNode* tailPrev = tail->prev;
    free(tail);

    tailPrev->next = phead;
    phead->prev = tailPrev;

}
void ListPopFront(ListNode* phead)
{
    assert(phead);
    assert(phead->next == phead);

    ListNode* first = phead->next;
    ListNode* second = first->next;
    free(first);

    phead->next = second;
    second->prev = phead;

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

