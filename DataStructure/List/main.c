#include "SList.h"

void TestSList1()
{
    SLTNode* plist = NULL;
    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);

    SListPushFront(&plist, 5);

    SListPrint(plist);

}

int main()
{
    TestSList1();

    return 0;
}
