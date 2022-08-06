//
// Created by Ðñ¸ç on 2022-08-06.
//

#include "SList.h"

void SListPrint(SLTNode* plist)
{
    SLTNode* cur = plist;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
