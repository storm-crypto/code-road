//
// Created by 旭哥 on 2022-08-09.
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
    int top;      // 栈顶
    int capacity; // 容量，方便增容
};

typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);

// 性质规定决定了在栈顶出和入
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

// 取栈顶数据
STDataType StackTop(Stack* pst);

// 空返回1，非空返回0
//int StackEmpty(Stack* pst);

bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);



#endif//STACKQUEUE_STACK_H
