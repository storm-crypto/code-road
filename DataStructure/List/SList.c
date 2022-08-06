//
// Created by ��� on 2022-08-06.
//

#include "SList.h"

void SListPrint(SLTNode* plist)
{
    SLTNode* cur = plist;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
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
