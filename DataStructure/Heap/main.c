#include "Heap.h"

// 排升序，建大堆
void HeapSort(int* a, int n)
{
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        // 选出次大的
        AdjustDown(a, end - 1, 0);
        --end;
    }
}

int main()
{
    int a[] = {27,15,19,18,28,34,65,49,25,37};
    int n = sizeof (a) / sizeof (a[0]);
    //AdjustDown(a, n, 0);
//    for (int i = (n - 1 -1 ) / 2; i >= 0; --i)
//    {
//        AdjustDown(a, n, i);
//    }
//    HeapSort(a, n);

    HP hp;
    HeapInit(&hp, a, n);
    HeapPrint(&hp);

    HeapDestroy(&hp);

    return 0;
}
