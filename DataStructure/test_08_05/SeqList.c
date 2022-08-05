//
// Created by Ðñ¸ç on 2022-08-05.
//

#include "SeqList.h"


void SeqListInit(SeqList* pq)
{
    assert(pq);

    pq->a = NULL;
    pq->size = pq->capacity = 0;
}

void SeqListDestory(SeqList* pq)
{
    assert(pq);

    free(pq->a);
    pq->a = NULL;
    pq->size = pq->capacity = 0;
}
