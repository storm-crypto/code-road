#include "SeqList.h"

void TestSeqList1()
{
    SeqList s;
    SeqListInit(&s);

    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    SeqListPushFront(&s, 0);
    SeqListPushFront(&s, 0);
    SeqListPushFront(&s, 0);
    SeqListPushFront(&s, 0);
    SeqListPrint(&s);

    SeqListPopBack(&s);
    SeqListPrint(&s);

    SeqListPopBack(&s);
    SeqListPrint(&s);

    SeqListPopFront(&s);
    SeqListPrint(&s);

    SeqListPopFront(&s);
    SeqListPrint(&s);

    SeqListDestory(&s);
}

void TestSeqList2()
{
    SeqList s;
    SeqListInit(&s);

    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    SeqListPrint(&s);

    SeqListInsert(&s, 2, 30);
    SeqListPrint(&s);

    SeqListDestory(&s);
}


int main()
{
    //TestSeqList1();
    TestSeqList2();

    return 0;
}
