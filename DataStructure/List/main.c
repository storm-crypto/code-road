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

void TestSList2() {
    SLTNode *plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPrint(plist);

    SListPopFront(&plist);

    SListPrint(plist);
}

int main()
{
    //TestSList1();
    TestSList2();

    return 0;
}
