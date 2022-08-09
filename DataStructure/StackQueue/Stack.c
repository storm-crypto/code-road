//
// Created by ��� on 2022-08-09.
//

#include "Stack.h"

void StackInit(Stack* pst)
{
    assert(pst);

//    pst->a = NULL;
//    pst->top = 0;
//    pst->capacity = 0;

    pst->a = (STDataType*)malloc(sizeof (STDataType));
    pst->top = 0;
    pst->capacity = 4;
}
void StackDestory(Stack* pst);

// ���ʹ涨��������ջ��������
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

// ȡջ������
STDataType StackTop(Stack* pst);

// �շ���1���ǿշ���0
//int StackEmpty(Stack* pst);

bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);
