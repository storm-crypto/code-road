#include "Sort.h"

int main()
{

    int arr[] = {1, 2, 4, 3, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, size);
    Print(arr, size);

    return 0;
}
