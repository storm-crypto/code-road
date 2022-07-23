#include <stdio.h>

void test(int arr[10])
{}
// 一维数组，形参部分的数组的大小
void test(int arr[])
{}



int main()
{
    int arr[10] = {0};
    int *arr2[20] = {0};
    test(arr);

    return 0;
}
