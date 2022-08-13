#include "Sort.h"

void TestInserSort()
{
    int arr[] = {1, 2, 4, 3, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, size);
    Print(arr, size);
}

void TestShellSort()
{
    int arr[] = {1, 2, 4, 3, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, size);
    Print(arr, size);
}

void TestSelectSort()
{
    int arr[] = {1, 2, 4, 3, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    SelectSort(arr, size);
    Print(arr, size);
}

void TestHeaptSort()
{
    int arr[] = {1, 2, 4, 3, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, size);
    Print(arr, size);
}

int main()
{
    TestShellSort();
    TestSelectSort();
    TestHeaptSort();
    return 0;
}
