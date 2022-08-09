//
// Created by ��� on 2022-08-09.
//

#ifndef STACKQUEUE_STACK_H
#define STACKQUEUE_STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int STDataType;
struct Stack
{
    STDataType* a;
    int top;      // ջ��
    int capacity; // ��������������
};

typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack* pst);
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



#endif//STACKQUEUE_STACK_H
