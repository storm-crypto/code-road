#include "SList.h"

void TestSList1()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);

    SListPrint(plist);

    SListPushFront(&plist, 0);
    SListPrint(plist);

    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPopBack(&plist);

    SListPrint(plist);

}

void TestSList2()
{
    SLTNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPrint(plist);

    SListPopFront(&plist);


    SListPrint(plist);
}

void TestSList3()
{
    SLTNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPrint(plist);

    SLTNode* pos = SListFind(plist, 3);
    if (pos)
    {
        printf("找到了\n");
    }
    else
    {
        printf("没有找到\n");
    }

    SListPrint(plist);
}

void TestSList4()
{
    SLTNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPrint(plist);

    SLTNode* pos = SListFind(plist, 3);
    SListInsertAfter(pos, 30);
    SListInsertBefore(&plist, pos, 300);

    SListPrint(plist);
}

int main()
{
    //TestSList1();
    //TestSList2();
    //TestSList3();
    TestSList4();

    return 0;
}
