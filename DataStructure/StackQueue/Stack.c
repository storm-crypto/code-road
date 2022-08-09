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
void StackDestory(Stack* pst)
{
    assert(pst);
    free(pst->a);
    pst->a = NULL;
    pst->top = pst->capacity = 0;
}

// 性质规定决定了在栈顶出和入
void StackPush(Stack* pst, STDataType x)
{
    assert(pst);
    // 增容
    if (pst->top == pst->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*(pst->capacity)*2);
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1); // 结束整个程序
        }

        pst->a = tmp;
        pst->capacity *= 2;
    }

    pst->a[pst->top] = x;
    pst->top++;

}
void StackPop(Stack* pst)
{
    assert(pst);
    assert(!StackEmpty(pst)); // 保证是非空的

    pst->top--;
}

// 取栈顶数据
STDataType StackTop(Stack* pst)
{
    assert(pst);
    assert(!StackEmpty(pst));

    return pst->a[pst->top - 1];

}

// 空返回1，非空返回0
//int StackEmpty(Stack* pst);

bool StackEmpty(Stack* pst);
int StackSize(Stack* pst);
