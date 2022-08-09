//
// Created by 旭哥 on 2022-08-09.
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

// 性质规定决定了在栈顶出和入
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);

// 取栈顶数据
STDataType StackTop(Stack* pst);

// 空返回1，非空返回0
//int StackEmpty(Stack* pst);

bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);
