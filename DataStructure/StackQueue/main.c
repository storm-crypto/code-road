#include "Stack.h"

void TestStack()
{
    Stack st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);

    // ±È¿˙’ª
    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }

    StackDestory(&st);

}

int main()
{
    TestStack();

    return 0;
}
