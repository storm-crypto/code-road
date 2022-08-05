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

    SeqListPrint(&s);

    SeqListDestory(&s);
}

int main()
{
    TestSeqList1();


    return 0;
}
