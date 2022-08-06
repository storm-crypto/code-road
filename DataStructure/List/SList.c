//
// Created by ��� on 2022-08-06.
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

// ����һ�����
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
    // Ҫ����һ���ж�һ�£����������һ���ͻᵼ�¿�ָ���쳣
    if (*pplist == NULL)
    {
        *pplist = newNode;
    }
    else
    {
        SLTNode* tail = *pplist;
        // �����һ�����ĵ�ַ������������պ���tailָ�����һ�����ĵ�ַ
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
    // 1. û�нڵ�
    // 2. һ���ڵ�
    // 3. ����ڵ�
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

// �������
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