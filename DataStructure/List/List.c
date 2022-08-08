//
// Created by Ğñ¸ç on 2022-08-08.
//

#include "List.h"


struct ListNode* BuyListNode(LTDataType x)
{
    ListNode* node = (ListNode*)malloc(sizeof (ListNode));
    node->next = NULL;
    node->prev = NULL;
    return node;
}

ListNode* ListInit()
{
    ListNode* phead = BuyListNode(0);
    phead->next = phead;
    phead->prev = phead;

    return phead;
}
