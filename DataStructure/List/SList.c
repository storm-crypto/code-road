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

// ��������
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

// ��������posλ�ú������x
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
    assert(pos);

    SLTNode* newNode = BuySLTNode(x);
    newNode->next = pos->next;
    pos->next = newNode;
}

// ��������posλ��֮ǰ����x(���鷳�����ʺϵ�����)
// ��Ҫ�ҵ�pos֮ǰ��λ�ã�������Ҫplist
// ������Ҫ�ı�plist�ĵ�ַ�����Բ���Ҫ�Ƕ���ָ��
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
    assert(pos);

    SLTNode* newNode = BuySLTNode(x);

    // �������
    if (pos == *pplist) // ͷ��
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

    // �Լ����ǵ�һ�����൱����ͷɾ
    if (*pplist == pos)
    {
        SListPopFront(pplist);
    }

    // �����������Ҫ�ҵ�posλ�õ�ǰһ��λ��
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