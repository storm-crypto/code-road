#include "SList.h"
#include "List.h"

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
        printf("�ҵ���\n");
    }
    else
    {
        printf("û���ҵ�\n");
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

void TestList1()
{
    ListNode* plist = ListInit();
    ListPushBack(plist, 1);
    ListPushBack(plist, 2);
    ListPushBack(plist, 3);
    ListPushBack(plist, 4);
    ListPushBack(plist, 5);

}

int main()
{
    //TestSList1();
    //TestSList2();
    //TestSList3();
    TestSList4();

    return 0;
}
