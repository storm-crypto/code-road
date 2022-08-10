#include "Stack.h"
#include "Queue.h"

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

void TestQueue()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);

    while (!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }

    QueueDestroy(&q);

}

int main()
{
    // TestStack();
    TestQueue();

    return 0;
}
